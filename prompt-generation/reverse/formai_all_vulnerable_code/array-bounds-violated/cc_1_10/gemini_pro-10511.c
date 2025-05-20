//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_PLAYERS 100

struct player {
    char name[256];
    int score;
    int x;
    int y;
};

struct game {
    struct player players[MAX_PLAYERS];
    int num_players;
    int game_over;
};

struct game game;

void init_game() {
    game.num_players = 0;
    game.game_over = 0;
}

void add_player(char *name) {
    if (game.num_players >= MAX_PLAYERS) {
        return;
    }

    strcpy(game.players[game.num_players].name, name);
    game.players[game.num_players].score = 0;
    game.players[game.num_players].x = 0;
    game.players[game.num_players].y = 0;

    game.num_players++;
}

void remove_player(char *name) {
    int i;

    for (i = 0; i < game.num_players; i++) {
        if (strcmp(game.players[i].name, name) == 0) {
            break;
        }
    }

    if (i == game.num_players) {
        return;
    }

    for (; i < game.num_players - 1; i++) {
        game.players[i] = game.players[i + 1];
    }

    game.num_players--;
}

void update_player(char *name, int x, int y) {
    int i;

    for (i = 0; i < game.num_players; i++) {
        if (strcmp(game.players[i].name, name) == 0) {
            break;
        }
    }

    if (i == game.num_players) {
        return;
    }

    game.players[i].x = x;
    game.players[i].y = y;
}

void send_update() {
    int i;

    for (i = 0; i < game.num_players; i++) {
        printf("%s %d %d\n", game.players[i].name, game.players[i].x, game.players[i].y);
    }
}

void handle_player(int sock) {
    char buf[256];
    int n;

    while ((n = recv(sock, buf, sizeof(buf), 0)) > 0) {
        buf[n - 1] = '\0';

        if (strncmp(buf, "ADD ", 4) == 0) {
            add_player(buf + 4);
        } else if (strncmp(buf, "REMOVE ", 7) == 0) {
            remove_player(buf + 7);
        } else if (strncmp(buf, "UPDATE ", 7) == 0) {
            char *name = strtok(buf + 7, " ");
            int x = atoi(strtok(NULL, " "));
            int y = atoi(strtok(NULL, " "));

            update_player(name, x, y);
        } else if (strncmp(buf, "SEND ", 5) == 0) {
            send_update();
        }
    }

    close(sock);
}

int main() {
    int sockfd, new_sock;
    struct sockaddr_in addr;
    socklen_t addr_len;
    pid_t pid;

    init_game();

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 10) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        addr_len = sizeof(addr);
        new_sock = accept(sockfd, (struct sockaddr *)&addr, &addr_len);
        if (new_sock == -1) {
            perror("accept");
            exit(1);
        }

        pid = fork();
        if (pid == 0) {
            close(sockfd);
            handle_player(new_sock);
            exit(0);
        } else {
            close(new_sock);
        }
    }

    close(sockfd);

    return 0;
}
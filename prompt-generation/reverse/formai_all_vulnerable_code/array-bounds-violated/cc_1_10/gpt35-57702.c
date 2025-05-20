//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILES 100

typedef struct File {
    char name[100];
    bool is_infected;
} File;

typedef struct Player {
    int id;
    int score;
} Player;

void scan_files(File files[MAX_FILES]) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i].name[0] == '\0') {
            continue;
        }
        FILE *fp;
        fp = fopen(files[i].name, "r");
        if (fp == NULL) {
            printf("Could not open file %s\n", files[i].name);
            continue;
        }
        char c;
        bool is_infected = false;
        while ((c = fgetc(fp)) != EOF) {
            if (c == 'v' || c == 'i' || c == 'r' || c == 'u' || c == 's') {
                is_infected = true;
                break;
            }
        }
        fclose(fp);
        files[i].is_infected = is_infected;
    }
}

void print_files(File files[MAX_FILES]) {
    printf("\nFiles:\n");
    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i].name[0] == '\0') {
            continue;
        }
        printf("%s - ", files[i].name);
        if (files[i].is_infected) {
            printf("INFECTED\n");
        } else {
            printf("CLEAN\n");
        }
    }
}

void print_scoreboard(Player players[], int num_players) {
    printf("\nScoreboard:\n");
    for (int i = 0; i < num_players; i++) {
        printf("Player %d: %d\n", players[i].id, players[i].score);
    }
}

void remove_newline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

int main() {
    File files[MAX_FILES] = {
        {"file1.txt", false},
        {"file2.doc", false},
        {"file3.exe", false},
        {"file4.jpg", false},
        {"file5.pdf", false},
    };
    int num_players;
    printf("Enter number of players: ");
    scanf("%d", &num_players);
    Player players[num_players];
    for (int i = 0; i < num_players; i++) {
        players[i].id = i+1;
        players[i].score = 0;
    }
    printf("\nWelcome to C Antivirus scanner!\n"
            "You and your friends will take turns scanning files.\n"
            "Earn points for finding infected files and lose points\n"
            "if you miss an infected file. The player with the most\n"
            "points after all files have been scanned wins!\n");
    int current_player = 0;
    int total_files = MAX_FILES;
    while (total_files > 0) {
        printf("\nPlayer %d's turn:", players[current_player].id);
        print_files(files);
        char filename[100];
        printf("Enter file name to scan (or q to quit): ");
        fgets(filename, 100, stdin);
        remove_newline(filename);
        if (strcmp(filename, "q") == 0) {
            break;
        }
        bool file_found = false;
        for (int i = 0; i < MAX_FILES; i++) {
            if (strcmp(files[i].name, filename) == 0) {
                file_found = true;
                if (files[i].is_infected) {
                    printf("Infected file found! Player %d earns 10 points.\n", players[current_player].id);
                    players[current_player].score += 10;
                } else {
                    printf("Clean file found. Player %d loses 5 points.\n", players[current_player].id);
                    players[current_player].score -= 5;
                }
                total_files--;
                files[i].name[0] = '\0';
                break;
            }
        }
        if (!file_found) {
            printf("File not found.\n");
        }
        scan_files(files);
        current_player = (current_player + 1) % num_players;
    }
    print_scoreboard(players, num_players);
    return 0;
}
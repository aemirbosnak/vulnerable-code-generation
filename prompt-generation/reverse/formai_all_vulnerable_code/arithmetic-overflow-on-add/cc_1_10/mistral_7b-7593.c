//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define BASE_ADDR 0x1000
#define DATA_SIZE 1024

typedef struct {
    char name[32];
    int level;
    int hp;
    int mp;
    int exp;
    int gold;
} CHARACTER;

int main() {
    CHARACTER player;
    int fd, i;

    memset(&player, 0, sizeof(player));
    strcpy(player.name, "Neo");
    player.level = 1;
    player.hp = 100;
    player.mp = 50;
    player.exp = 0;
    player.gold = 0;

    fd = open("save.dat", O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) {
        perror("Error opening save file");
        return 1;
    }

    write(fd, &player, sizeof(player));
    close(fd);

    printf("Saved character data:\n");
    printf("Name: %s\n", player.name);
    printf("Level: %d\n", player.level);
    printf("HP: %d\n", player.hp);
    printf("MP: %d\n", player.mp);
    printf("EXP: %d\n", player.exp);
    printf("Gold: %d\n", player.gold);

    for (i = 0; i < 10; i++) {
        sleep(1);

        fd = open("save.dat", O_RDWR, 0);
        if (fd < 0) {
            perror("Error opening save file");
            return 1;
        }

        read(fd, &player, sizeof(player));
        close(fd);

        player.exp += rand() % 10 + 1;
        player.gold += rand() % 5 + 1;

        fd = open("save.dat", O_WRONLY, 0);
        if (fd < 0) {
            perror("Error opening save file");
            return 1;
        }

        write(fd, &player, sizeof(player));
        close(fd);

        printf("Experience: %d\n", player.exp);
        printf("Gold: %d\n", player.gold);
    }

    return 0;
}
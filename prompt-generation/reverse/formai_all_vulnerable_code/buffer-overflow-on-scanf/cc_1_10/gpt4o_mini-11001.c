//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void print_puzzle_line(const char *line, int offset) {
    int len = strlen(line);
    // Create an offset cycled string
    for (int i = 0; i < len; i++) {
        putchar(line[(i + offset) % len]);
    }
    putchar('\n');
}

void execute_command(const char *command, int puzzle_offset) {
    FILE *fp;
    char buffer[MAX_LINE_LENGTH];

    fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n" );
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        print_puzzle_line(buffer, puzzle_offset);
    }

    pclose(fp);
}

int main() {
    int choice;
    
    while (1) {
        printf("Welcome to the Puzzling System Admin Tool!\n");
        printf("1. Check Disk Usage\n");
        printf("2. Check Uptime\n");
        printf("3. Exit\n");
        printf("Choose your destiny (1-3): ");
        
        scanf("%d", &choice);
        getchar(); // To consume the newline after scanf

        if (choice == 1) {
            printf("So you want to see how much space you have, do ya?\n");
            printf("Here we go, let’s unravel the mystery of your disk!\n");
            execute_command("df -h", 3);
        } else if (choice == 2) {
            printf("Time flies, but can you catch it?\n");
            printf("Let’s find out how long the journey has been!\n");
            execute_command("uptime", 5);
        } else if (choice == 3) {
            printf("Oh, the end of a journey! Farewell!\n");
            break;
        } else {
            printf("That choice does not exist in this realm... Try again!\n");
        }
    }

    return 0;
}
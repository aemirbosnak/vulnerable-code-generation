//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_COMMAND_LENGTH 1024
#define JOKES_COUNT 5

void print_joke() {
    const char *jokes[JOKES_COUNT] = {
        "Why don't scientists trust atoms? Because they make up everything!",
        "Why did the chicken cross the playground? To get to the other slide!",
        "What do you call a fake noodle? An impasta!",
        "Why did the tomato turn red? Because it saw the salad dressing!",
        "Why did the scarecrow win an award? Because he was outstanding in his field!"
    };

    int random_joke = rand() % JOKES_COUNT;
    printf("\n%s\n", jokes[random_joke]);
}

void play_melody() {
    int melody[] = {261, 329, 329, 329, 293, 293, 293, 261};

    for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
        printf("\007");
        usleep(100000);
        printf("\007");
        usleep(100000);
        printf("\007");
        usleep(100000);
        printf("\007");
        usleep(100000);
        printf("\007");
        usleep(100000);
        printf("\007");
        usleep(100000);
    }
}

int main() {
    srand(time(NULL));
    FILE *file = fopen("commands.txt", "r");
    char command[MAX_COMMAND_LENGTH];
    size_t bytes_read;

    if (file == NULL) {
        perror("Error opening the file");
        exit(EXIT_FAILURE);
    }

    printf("Welcome to the crazy shell!\n");
    print_joke();

    while (fgets(command, MAX_COMMAND_LENGTH, file)) {
        bytes_read = strlen(command);
        command[bytes_read - 1] = '\0'; // remove newline character
        printf("\nExecuting command: %s\n", command);
        system(command);
        printf("\nCommand executed!\n");
        if (rand() % 2) {
            play_melody();
        }
        print_joke();
    }

    fclose(file);
    printf("\nShell exiting...\n");
    return EXIT_SUCCESS;
}
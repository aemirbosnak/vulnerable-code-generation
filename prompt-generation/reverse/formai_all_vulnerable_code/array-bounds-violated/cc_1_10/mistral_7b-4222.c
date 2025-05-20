//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 256
#define MIN_LENGTH 10
#define MAX_TRIES 5
#define NUM_CHARS 26

typedef struct {
    char name[50];
    long time;
} Record;

void generateString(char *str, int length) {
    int i;
    for (i = 0; i < length; i++) {
        str[i] = (char)(rand() % NUM_CHARS + 'a');
        if (i > 0 && rand() % 3)
            str[i] = (char)(rand() % NUM_CHARS + 'A');
        if (i > 0 && rand() % 5)
            str[i] = (char)(rand() % 10 + '0');
        if (i > 0 && rand() % 10 == 0)
            str[i] = '_';
    }
    str[length] = '\0';
}

int main() {
    srand(time(NULL));
    char str[MAX_LENGTH];
    int length, tries, keyPressed;
    long startTime, elapsedTime;
    FILE *file = fopen("records.txt", "a+");

    if (file == NULL) {
        printf("Error: Unable to open records file.\n");
        return 1;
    }

    while (1) {
        printf("\n--- TYPING SPEED TEST ---\n");
        printf("Enter your name: ");
        fgets(str, sizeof(str), stdin);
        str[strlen(str) - 1] = '\0';

        length = rand() % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH;
        generateString(str, length);
        printf("Type the following string:\n'%s'\n", str);

        startTime = clock();
        tries = 0;
        for (; tries < MAX_TRIES; tries++) {
            fflush(stdout);
            scanf("%s", str);
            if (strcmp(str, getpass(NULL)) == 0) {
                elapsedTime = clock() - startTime;
                fprintf(file, "%s,%ld\n", str, elapsedTime);
                printf("Correct! Your time is %ld ms.\n", elapsedTime);
                break;
            }
            printf("Incorrect. Try again.\n");
            printf("'%s'\n", getpass(NULL));
            sleep(1);
        }

        if (tries == MAX_TRIES) {
            printf("Max attempts reached. Better luck next time!\n");
            fprintf(file, "%s,Error\n", str);
        }
        printf("Press any key to continue...\n");
        getchar();
    }

    fclose(file);
    return 0;
}
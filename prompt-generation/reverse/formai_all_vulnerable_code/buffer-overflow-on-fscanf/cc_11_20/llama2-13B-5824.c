//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_NAME_LENGTH 255
#define MAX_QUESTIONS 10

struct knight {
    char name[MAX_NAME_LENGTH];
    char question[MAX_QUESTIONS][255];
    int score;
};

int main() {
    struct knight knights[5];
    int i;

    // Load the knights from a file
    FILE *file = fopen("knights.txt", "r");
    if (file == NULL) {
        perror("Failed to open knights.txt");
        return 1;
    }

    for (i = 0; i < 5; i++) {
        fscanf(file, "%s %s %d", knights[i].name, knights[i].question[0], &knights[i].score);
    }

    fclose(file);

    // Print the knights' names and questions
    for (i = 0; i < 5; i++) {
        printf("%s: %s\n", knights[i].name, knights[i].question[0]);
    }

    // Allow the user to choose a knight and answer their question
    for (i = 0; i < 5; i++) {
        printf("%d: %s\n", i, knights[i].name);
    }

    int chosen_knight = getchar();
    if (chosen_knight == '1' || chosen_knight == '2' || chosen_knight == '3' || chosen_knight == '4' || chosen_knight == '5') {
        int answer = getchar();
        if (answer == 'a' || answer == 'A') {
            knights[chosen_knight - 1].score++;
            printf("Correct! You have %d points.\n", knights[chosen_knight - 1].score);
        } else {
            printf("Incorrect. The correct answer is %c.\n", 'a');
        }
    } else {
        printf("Invalid choice. Please enter a number from 1 to 5.\n");
    }

    // Print the final scores
    for (i = 0; i < 5; i++) {
        printf("%d: %s (%d points)\n", i, knights[i].name, knights[i].score);
    }

    return 0;
}
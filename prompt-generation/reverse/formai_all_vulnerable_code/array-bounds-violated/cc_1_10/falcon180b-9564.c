//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, correct = 0, wrong = 0, total = 0, score = 0;
    float speed = 0, accuracy = 0;
    char text[1000], input[50];
    FILE *file;
    time_t start, end;

    printf("Welcome to the Romantic Typing Speed Test!\n");
    printf("Select a text file to type from:\n");
    printf("1. Romeo and Juliet\n");
    printf("2. Sonnet 18\n");
    printf("3. Your own text file\n");
    scanf("%d", &choice);

    if (choice == 1) {
        file = fopen("romeo_and_juliet.txt", "r");
    } else if (choice == 2) {
        file = fopen("sonnet_18.txt", "r");
    } else if (choice == 3) {
        printf("Enter the path to your text file: ");
        scanf("%s", input);
        file = fopen(input, "r");
    } else {
        printf("Invalid choice.\n");
        return 0;
    }

    if (file == NULL) {
        printf("File not found.\n");
        return 0;
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    text[size] = '\0';
    fgets(text, size, file);
    fclose(file);

    printf("Type the following text:\n%s\n", text);

    time(&start);
    while (fgets(input, 50, stdin)!= NULL) {
        if (strcmp(input, text) == 0) {
            correct++;
        } else {
            wrong++;
        }
        total++;
    }
    time(&end);

    speed = (float)total / (end - start);
    accuracy = (float)correct / total * 100;

    printf("\nResults:\n");
    printf("Correct words: %d\n", correct);
    printf("Wrong words: %d\n", wrong);
    printf("Total words: %d\n", total);
    printf("Speed: %.2f wpm\n", speed);
    printf("Accuracy: %.2f%%\n", accuracy);

    if (wrong == 0) {
        printf("\nCongratulations, you have achieved 100% accuracy!\n");
    }

    score = speed * accuracy / 100;
    printf("Your final score is: %.2f\n", score);

    return 0;
}
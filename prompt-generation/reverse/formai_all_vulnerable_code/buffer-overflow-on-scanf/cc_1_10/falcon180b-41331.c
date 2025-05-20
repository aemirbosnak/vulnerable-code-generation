//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    char text[1000];
    int length, correct, incorrect, speed;
    float accuracy;
    char filename[20];
    FILE *fp;

    printf("Welcome to the Happy Typing Speed Test!\n");
    printf("Please choose a difficulty level:\n");
    printf("1. Easy\n2. Medium\n3. Hard\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            strcpy(text, "The quick brown fox jumps over the lazy dog.");
            length = strlen(text);
            break;
        case 2:
            strcpy(text, "Sphinx of black quartz, judge my vow.");
            length = strlen(text);
            break;
        case 3:
            strcpy(text, "Pack my box with five dozen liquor jugs.");
            length = strlen(text);
            break;
        default:
            printf("Invalid choice. Exiting...\n");
            exit(0);
    }

    printf("Please enter your name:\n");
    scanf("%s", filename);
    strcat(filename, ".txt");

    fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error creating file. Exiting...\n");
        exit(0);
    }

    correct = 0;
    incorrect = 0;

    clock_t start_time = clock();
    printf("Start typing:\n%s", text);
    fflush(stdout);

    while(1) {
        char c = getchar();
        if(c == '\n') {
            break;
        }

        if(c!= text[correct]) {
            incorrect++;
        } else {
            correct++;
        }
    }

    clock_t end_time = clock();
    speed = (float)correct / (end_time - start_time) * 60;
    accuracy = (float)correct / length * 100;

    printf("\nYou typed %d characters correctly and %d characters incorrectly.\n", correct, incorrect);
    printf("Your typing speed is %.2f characters per minute with an accuracy of %.2f%%.\n", speed, accuracy);

    fclose(fp);
    return 0;
}
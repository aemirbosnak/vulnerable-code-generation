//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 10
#define MAX_LENGTH 256

void displayGreeting();
int getRandomIndex(int max);
void displayFortune(char *fortune);
void addFortune(char fortunes[][MAX_LENGTH], int *count);
void saveFortunesToFile(char fortunes[][MAX_LENGTH], int count);
void loadFortunesFromFile(char fortunes[][MAX_LENGTH], int *count);

int main() {
    char fortunes[MAX_FORTUNES][MAX_LENGTH];
    int count = 0;
    int option;

    loadFortunesFromFile(fortunes, &count);

    while(1) {
        displayGreeting();
        printf("Choose an option:\n");
        printf("1. Get a fortune\n");
        printf("2. Add a new fortune\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                if (count > 0) {
                    int randomIndex = getRandomIndex(count);
                    displayFortune(fortunes[randomIndex]);
                } else {
                    printf("No fortunes available. Please add some first.\n");
                }
                break;
            case 2:
                addFortune(fortunes, &count);
                break;
            case 3:
                saveFortunesToFile(fortunes, count);
                printf("Goodbye! Your fortunes have been saved.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
}

void displayGreeting() {
    printf("*****************************\n");
    printf("*      Automated Fortune     *\n");
    printf("*          Teller            *\n");
    printf("*****************************\n");
}

int getRandomIndex(int max) {
    srand(time(NULL));
    return rand() % max;
}

void displayFortune(char *fortune) {
    printf("Your fortune: %s\n", fortune);
}

void addFortune(char fortunes[][MAX_LENGTH], int *count) {
    if (*count < MAX_FORTUNES) {
        char newFortune[MAX_LENGTH];
        printf("Enter the new fortune: ");
        getchar(); // To clear the newline character from the buffer
        fgets(newFortune, MAX_LENGTH, stdin);
        newFortune[strcspn(newFortune, "\n")] = 0; // Remove newline character
        strcpy(fortunes[*count], newFortune);
        (*count)++;
        printf("Fortune added successfully!\n");
    } else {
        printf("Maximum number of fortunes reached. Please delete an existing fortune to add a new one.\n");
    }
}

void saveFortunesToFile(char fortunes[][MAX_LENGTH], int count) {
    FILE *file = fopen("fortunes.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < count; i++) {
            fprintf(file, "%s\n", fortunes[i]);
        }
        fclose(file);
    } else {
        printf("Could not open file for saving fortunes.\n");
    }
}

void loadFortunesFromFile(char fortunes[][MAX_LENGTH], int *count) {
    FILE *file = fopen("fortunes.txt", "r");
    if (file != NULL) {
        while (fgets(fortunes[*count], MAX_LENGTH, file) != NULL) {
            fortunes[*count][strcspn(fortunes[*count], "\n")] = 0; // Remove newline character
            (*count)++;
        }
        fclose(file);
    } else {
        printf("No existing fortunes found. You can add new fortunes!\n");
    }
}
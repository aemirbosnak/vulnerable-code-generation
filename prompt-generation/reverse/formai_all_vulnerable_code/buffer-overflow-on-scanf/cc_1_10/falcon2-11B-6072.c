//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char name[20];
    char description[50];
    char location[20];
    int hauntedness;
} house;

int main() {
    int n, i, choice;
    srand(time(0));
    house houses[10];
    char input[100];
    char prompt[50];

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Please enter the number of houses you would like to generate: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        sprintf(prompt, "Enter the name of House %d: ", i + 1);
        fgets(input, sizeof(input), stdin);
        strcpy(houses[i].name, input);

        sprintf(prompt, "Enter the description of House %d: ", i + 1);
        fgets(input, sizeof(input), stdin);
        strcpy(houses[i].description, input);

        sprintf(prompt, "Enter the location of House %d: ", i + 1);
        fgets(input, sizeof(input), stdin);
        strcpy(houses[i].location, input);

        houses[i].hauntedness = rand() % 10 + 1;
    }

    printf("\nHere are the houses you have generated:\n");
    for (i = 0; i < n; i++) {
        printf("House %d:\n", i + 1);
        printf("Name: %s\n", houses[i].name);
        printf("Description: %s\n", houses[i].description);
        printf("Location: %s\n", houses[i].location);
        printf("Hauntedness: %d\n", houses[i].hauntedness);
        printf("\n");
    }

    printf("\nDo you want to generate more houses? (y/n): ");
    scanf("%s", input);
    while (strcmp(input, "y") && strcmp(input, "Y")) {
        printf("\nInvalid input. Do you want to generate more houses? (y/n): ");
        scanf("%s", input);
    }

    if (strcmp(input, "y") || strcmp(input, "Y")) {
        for (i = 0; i < n; i++) {
            houses[i].hauntedness = rand() % 10 + 1;
        }

        printf("\nHere are the updated houses you have generated:\n");
        for (i = 0; i < n; i++) {
            printf("House %d:\n", i + 1);
            printf("Name: %s\n", houses[i].name);
            printf("Description: %s\n", houses[i].description);
            printf("Location: %s\n", houses[i].location);
            printf("Hauntedness: %d\n", houses[i].hauntedness);
            printf("\n");
        }
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    char name[50];
    char fortune[100];

    printf("Welcome to the Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    srand(time(NULL));
    int random_number = rand() % 10 + 1;

    switch(random_number) {
        case 1:
            strcpy(fortune, "You will have a great day today!");
            break;
        case 2:
            strcpy(fortune, "You will find love in unexpected places.");
            break;
        case 3:
            strcpy(fortune, "You will receive good news soon.");
            break;
        case 4:
            strcpy(fortune, "You will have a successful career.");
            break;
        case 5:
            strcpy(fortune, "You will travel to an exotic place.");
            break;
        case 6:
            strcpy(fortune, "You will overcome a challenge.");
            break;
        case 7:
            strcpy(fortune, "You will have a lucky streak.");
            break;
        case 8:
            strcpy(fortune, "You will meet someone new and exciting.");
            break;
        case 9:
            strcpy(fortune, "You will have a peaceful and relaxing day.");
            break;
        case 10:
            strcpy(fortune, "You will have a day full of surprises.");
            break;
    }

    printf("\nYour fortune is:\n");
    printf("%s\n", fortune);

    printf("\nPress any key to exit...\n");
    scanf("%d", &choice);

    return 0;
}
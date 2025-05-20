//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TRAVEL_OPTIONS 5

typedef struct {
    int year;
    char description[50];
} TimeMachine;

void displayMenu() {
    printf("=== Time Travel Simulator ===\n");
    printf("1. Travel to the past\n");
    printf("2. Travel to the future\n");
    printf("3. View travel history\n");
    printf("4. Quit\n");
    printf("============================\n");
}

void clearBuffer() {
    while (getchar() != '\n');
}

void timeTravel(TimeMachine history[], int *count) {
    int choice, year;
    char *direction;
    
    printf("Choose your destination:\n");
    printf("1. 5000 BC\n2. 1000 AD\n3. 1500 AD\n4. 2000 AD\n5. 3000 AD\n");

    scanf("%d", &choice);
    clearBuffer();

    if(choice < 1 || choice > MAX_TRAVEL_OPTIONS) {
        printf("Invalid choice! Please try again.\n");
        return;
    }

    switch (choice) {
        case 1: year = -5000; direction = "the past"; strcpy(history[*count].description, "5000 BC"); break;
        case 2: year = 1000; direction = "the past"; strcpy(history[*count].description, "1000 AD"); break;
        case 3: year = 1500; direction = "the past"; strcpy(history[*count].description, "1500 AD"); break;
        case 4: year = 2000; direction = "the present"; strcpy(history[*count].description, "2000 AD"); break;
        case 5: year = 3000; direction = "the future"; strcpy(history[*count].description, "3000 AD"); break;
    }
    
    history[*count].year = year;
    (*count)++;
    printf("You have successfully traveled to %s: %s!\n", direction, history[*count - 1].description);
}

void viewHistory(TimeMachine history[], int count) {
    if (count == 0) {
        printf("You have not traveled anywhere yet.\n");
        return;
    }

    printf("=== Travel History ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %d -> %s\n", i + 1, history[i].year, history[i].description);
    }
    printf("======================\n");
}

void saveHistory(TimeMachine history[], int count) {
    FILE *file = fopen("travel_history.txt", "w");
    if (file == NULL) {
        printf("Unable to save travel history!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d -> %s\n", history[i].year, history[i].description);
    }

    fclose(file);
    printf("Travel history saved successfully!\n");
}

int main() {
    TimeMachine travelHistory[100];
    int travelCount = 0;
    int option;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &option);
        clearBuffer();

        switch (option) {
            case 1:
                timeTravel(travelHistory, &travelCount);
                break;
            case 2:
                timeTravel(travelHistory, &travelCount);
                break;
            case 3:
                viewHistory(travelHistory, travelCount);
                break;
            case 4:
                printf("Thank you for using the Time Travel Simulator! Exiting...\n");
                saveHistory(travelHistory, travelCount);
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }
    return 0;
}
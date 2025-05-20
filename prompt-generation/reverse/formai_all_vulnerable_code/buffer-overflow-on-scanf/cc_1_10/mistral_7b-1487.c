//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DREAMS 10
#define DREAM_LENGTH 256
#define DREAM_NAME_LENGTH 50

typedef struct Dream {
    char name[DREAM_NAME_LENGTH];
    char description[DREAM_LENGTH];
    time_t time;
} Dream;

void saveDream(Dream *dreams, int index, char *name, char *description) {
    strcpy(dreams[index].name, name);
    strcpy(dreams[index].description, description);
    dreams[index].time = time(NULL);
}

void printDream(Dream dream) {
    printf("\nName: %s\nDescription: %s\nTime: %s", dream.name, dream.description, ctime(&dream.time));
}

void printDreams(Dream *dreams) {
    for (int i = 0; i < MAX_DREAMS; i++) {
        if (dreams[i].time != 0) {
            printDream(dreams[i]);
        }
    }
}

int main() {
    Dream dreams[MAX_DREAMS];
    char name[DREAM_NAME_LENGTH];
    char description[DREAM_LENGTH];

    int clockIndex = 0;

    while (1) {
        printf("\nWelcome to the Melting Clocks Digital Diary! \n");
        printf("Enter your dream's name: ");
        scanf("%s", name);

        printf("Describe your dream: ");
        scanf("%[^\n]", description);

        saveDream(dreams, clockIndex, name, description);

        int meltingClock = rand() % MAX_DREAMS;
        if (dreams[meltingClock].time != 0) {
            dreams[meltingClock].time = 0;
            printf("\nYour dream has replaced a melting dream! \n");
            printf("Name: %s\nDescription: %s\n", dreams[meltingClock].name, dreams[meltingClock].description);
        }

        clockIndex++;

        if (clockIndex == MAX_DREAMS) {
            printf("\nYour digital diary is full. Save it or clear some space? (1 for save, 0 for clear)\n");
            int choice;
            scanf("%d", &choice);

            if (choice == 1) {
                printf("\nSaving your digital diary...\n");
                FILE *file = fopen("digital_diary.dat", "wb");
                fwrite(dreams, sizeof(Dream), MAX_DREAMS, file);
                fclose(file);
                printf("\nDigital diary saved!\n");
                break;
            } else if (choice == 0) {
                for (int i = 0; i < MAX_DREAMS; i++) {
                    dreams[i].time = 0;
                }
                clockIndex = 0;
                printf("\nDiary cleared. Sweet dreams!\n");
            } else {
                printf("\nInvalid choice. Please try again.\n");
            }
        }
    }

    printDreams(dreams);

    return 0;
}
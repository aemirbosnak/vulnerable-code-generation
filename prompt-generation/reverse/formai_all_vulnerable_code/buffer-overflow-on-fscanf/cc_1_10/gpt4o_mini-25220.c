//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_COLOR_LENGTH 20

typedef struct {
    int age;
    char color[MAX_COLOR_LENGTH];
} Person;

int readData(const char *filename, Person people[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Oh no! Could not open the file: %s\n", filename);
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%d,%19[^,\n]", &people[count].age, people[count].color) != EOF && count < MAX_RECORDS) {
        count++;
        fgetc(file); // read the newline
    }

    fclose(file);
    printf("Yay! Successfully read %d records!\n", count);
    return count;
}

void findMostCommon(const Person people[], int count, int *commonAge, char *commonColor) {
    int ageCount[120] = {0}; // Assuming ages 0-119
    int colorCount[MAX_COLOR_LENGTH] = {0};
    int maxAgeCount = 0;
    int maxColorIndex = 0;

    for (int i = 0; i < count; i++) {
        ageCount[people[i].age]++;
        if (ageCount[people[i].age] > maxAgeCount) {
            maxAgeCount = ageCount[people[i].age];
            *commonAge = people[i].age;
        }

        // Check for color
        int index = -1;
        for (int j = 0; j < MAX_COLOR_LENGTH; j++) {
            if (strcmp(people[i].color, commonColor) == 0) {
                index = j;
                break;
            }
        }
        if (index != -1) {
            colorCount[i]++;
            if (colorCount[i] > colorCount[maxColorIndex]) {
                maxColorIndex = i;
                strcpy(commonColor, people[i].color);
            }
        }
    }
    printf("Hooray! The most common age is %d and the most loved color is %s!\n", *commonAge, commonColor);
}

int main() {
    printf("Welcome to the Happy Data Mining Tool!\n");
    Person people[MAX_RECORDS];
    int recordCount = readData("data.csv", people);
    
    if (recordCount <= 0) {
        printf("Oops! No data to analyze... Please check your file!\n");
        return 1;
    }

    int commonAge = 0;
    char commonColor[MAX_COLOR_LENGTH] = "none";
    
    findMostCommon(people, recordCount, &commonAge, commonColor);

    printf("Thank you for using the Happy Data Mining Tool! Keep smiling!\n");
    return 0;
}
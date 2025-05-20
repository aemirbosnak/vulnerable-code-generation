//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int age;
} Survivor;

void introduction() {
    printf("=== The Last Haven: Survivor Sorting Program ===\n");
    printf("In the year 2089, civilization has crumbled.\n");
    printf("The remaining survivors are scattered across the wasteland.\n");
    printf("To rebuild society, we must sort survivors based on their age.\n");
    printf("You will compile a list of survivors and sort them to plan for resources.\n");
    printf("===================================================\n");
}

void getInput(Survivor *survivors, int *count) {
    printf("Enter the number of survivors (up to %d): ", MAX_SIZE);
    scanf("%d", count);
    
    if (*count > MAX_SIZE) {
        printf("Cannot exceed %d survivors, setting count to %d.\n", MAX_SIZE, MAX_SIZE);
        *count = MAX_SIZE;
    }
    
    for (int i = 0; i < *count; i++) {
        printf("Enter survivor %d name: ", i + 1);
        scanf("%s", survivors[i].name);
        printf("Enter survivor %d age: ", i + 1);
        scanf("%d", &survivors[i].age);
    }
}

void swap(Survivor *a, Survivor *b) {
    Survivor temp = *a;
    *a = *b;
    *b = temp;
}

void sortSurvivors(Survivor *survivors, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (survivors[j].age > survivors[j + 1].age) {
                swap(&survivors[j], &survivors[j + 1]);
            }
        }
    }
}

void displaySurvivors(Survivor *survivors, int count) {
    printf("\nSorted List of Survivors by Age:\n");
    printf("===================================\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s, Age: %d\n", i + 1, survivors[i].name, survivors[i].age);
    }
    printf("===================================\n");
}

int main() {
    Survivor survivors[MAX_SIZE];
    int count = 0;

    introduction();
    getInput(survivors, &count);
    sortSurvivors(survivors, count);
    displaySurvivors(survivors, count);

    printf("As the sun sets over the wasteland, we prepare for tomorrow...\n");
    return 0;
}
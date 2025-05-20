//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_ENTRIES 100

struct entry{
    char name[50];
    int calories;
    int distance;
    int time;
};

void add_entry(struct entry entries[], int *count){
    printf("Enter name: ");
    scanf("%s", entries[*count].name);
    printf("Enter calories burned: ");
    scanf("%d", &entries[*count].calories);
    printf("Enter distance covered (in meters): ");
    scanf("%d", &entries[*count].distance);
    printf("Enter time taken (in seconds): ");
    scanf("%d", &entries[*count].time);
    (*count)++;
}

void display_entries(struct entry entries[], int count){
    printf("\nName\tCalories\tDistance\tTime\n");
    for(int i=0; i<count; i++){
        printf("%s\t%d\t%d\t%d\n", entries[i].name, entries[i].calories, entries[i].distance, entries[i].time);
    }
}

int main(){
    struct entry entries[MAX_ENTRIES];
    int count=0;

    while(count<MAX_ENTRIES){
        printf("\nEnter 1 to add an entry\nEnter 2 to display entries\nEnter 0 to exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_entry(entries, &count);
                break;
            case 2:
                display_entries(entries, count);
                break;
            case 0:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}
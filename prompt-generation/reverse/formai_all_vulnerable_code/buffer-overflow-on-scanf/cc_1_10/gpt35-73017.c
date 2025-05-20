//FormAI DATASET v1.0 Category: Database simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct suspect{
    int id;
    char name[50];
    char occupation[50];
    int age;
    char crime[100];
};

void add_suspect(struct suspect **arr, int *count){
    *count += 1;
    *arr = (struct suspect *) realloc(*arr, *count * sizeof(struct suspect));

    printf("\nEnter the following details of the suspect:\n");
    (*arr)[*count - 1].id = *count;

    printf("Name: ");
    scanf("%s", (*arr)[*count - 1].name);

    printf("Occupation: ");
    scanf("%s", (*arr)[*count - 1].occupation);

    printf("Age: ");
    scanf("%d", &((*arr)[*count - 1].age));

    printf("Crime committed: ");
    getchar();
    fgets((*arr)[*count - 1].crime, 100, stdin);
}

void list_suspects(struct suspect *arr, int count){
    if(count == 0){
        printf("\nNo suspects in the database.\n");
        return;
    }

    printf("\nSuspect ID\tName\t\tOccupation\tAge\tCrime committed\n");
    printf("--------------------------------------------------------------------------------\n");
    int i;
    for(i=0; i<count; i++){
        printf("%-12d%-18s%-16s%-12d%-s", arr[i].id, arr[i].name, arr[i].occupation, arr[i].age, arr[i].crime);
    }
}

int main()
{
    struct suspect *suspects = NULL;
    int suspect_count = 0;

    printf("**********************************\n");
    printf("*     Welcome to Sherlock DB     *\n");
    printf("**********************************\n");

    while(1){
        printf("\nEnter your choice:\n");
        printf("1. Add suspect\n2. List all suspects\n3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1: add_suspect(&suspects, &suspect_count); break;
            case 2: list_suspects(suspects, suspect_count); break;
            case 3: printf("\nThank you for using Sherlock DB!\n"); exit(0);
            default: printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}
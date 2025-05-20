//FormAI DATASET v1.0 Category: Database simulation ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct case_t {
    char case_id[10];
    char victim_name[50];
    char date[20];
    char location[100];
    char suspect_name[50];
} case_t;

case_t *add_case(case_t *cases, int *num_cases){
    cases = (case_t*)realloc(cases, (*num_cases + 1) * sizeof(case_t));
    printf("Enter case ID: ");
    scanf("%s", cases[*num_cases].case_id);
    printf("Enter victim name: ");
    scanf("%s", cases[*num_cases].victim_name);
    printf("Enter date: ");
    scanf("%s", cases[*num_cases].date);
    printf("Enter location: ");
    scanf("%s", cases[*num_cases].location);
    printf("Enter suspect name: ");
    scanf("%s", cases[*num_cases].suspect_name);
    (*num_cases)++;
    return cases;
}

void display_cases(case_t *cases, int num_cases){
    printf("==============================================================\n");
    printf("%-10s%-20s%-20s%-30s%-20s\n", "Case ID", "Victim Name", "Date", "Location", "Suspect Name");
    printf("==============================================================\n");
    for(int i=0; i<num_cases; i++){
        printf("%-10s%-20s%-20s%-30s%-20s\n", cases[i].case_id, cases[i].victim_name, cases[i].date, cases[i].location, cases[i].suspect_name);
    }
    printf("==============================================================\n");
}

void search_case(case_t *cases, int num_cases){
    char search_id[10];
    printf("Enter case ID to search: ");
    scanf("%s", search_id);
    for(int i=0; i<num_cases; i++){
        if(strcmp(cases[i].case_id, search_id) == 0){
            printf("Case found:\n");
            printf("%-10s%-20s%-20s%-30s%-20s\n", "Case ID", "Victim Name", "Date", "Location", "Suspect Name");
            printf("%-10s%-20s%-20s%-30s%-20s\n", cases[i].case_id, cases[i].victim_name, cases[i].date, cases[i].location, cases[i].suspect_name);
            return;
        }
    }
    printf("Case not found.\n");
}

int main(){
    case_t *cases = NULL;
    int num_cases = 0;
    char choice;

    printf("Welcome to the Sherlock Holmes Criminal Database Simulation!\n");
    do {
        printf("\nMenu:\n");
        printf("1. Add case\n");
        printf("2. Display all cases\n");
        printf("3. Search case\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice){
            case '1': cases = add_case(cases, &num_cases); break;
            case '2': display_cases(cases, num_cases); break;
            case '3': search_case(cases, num_cases); break;
            case '4': printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n"); break;
        }
    } while(choice != '4');

    return 0;
}
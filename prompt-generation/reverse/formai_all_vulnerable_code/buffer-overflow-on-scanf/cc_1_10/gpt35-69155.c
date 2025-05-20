//FormAI DATASET v1.0 Category: File handling ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>

// Define a struct to hold the details of a case
struct Case{
    char title[100];
    char victim[100];
    char perpetrator[100];
    int year;
};

int main(){
    // Prompt the user to enter the name of the file
    printf("Enter the name of the case file to create: ");
    char file_name[100];
    scanf("%s", file_name);

    // Open the file for writing
    FILE* fp = fopen(file_name, "w");
    if(fp == NULL){
        printf("Error: Unable to create file!\n");
        exit(1);
    }

    // Prompt the user to enter the details of the case-file
    int num_cases;
    printf("Enter the number of cases to record: ");
    scanf("%d", &num_cases);

    // Write the case details to the file using fwrite function
    for(int i=0; i<num_cases; i++){
        struct Case c;
        printf("Enter details of case %d:\n", i+1);
        printf("Title: ");
        scanf(" %[^\n]s", c.title);
        printf("Victim: ");
        scanf(" %[^\n]s", c.victim);
        printf("Perpetrator: ");
        scanf(" %[^\n]s", c.perpetrator);
        printf("Year: ");
        scanf("%d", &c.year);
        fwrite(&c, sizeof(struct Case), 1, fp);
    }

    // Close the file
    fclose(fp);

    // Open the file for reading
    fp = fopen(file_name, "r");
    if(fp == NULL){
        printf("Error: Unable to open file!\n");
        exit(1);
    }

    // Read the case details from file and print them
    printf("\nDetails of cases recorded:\n");
    for(int i=0; i<num_cases; i++){
        struct Case c;
        fread(&c, sizeof(struct Case), 1, fp);
        printf("Case %d:\n", i+1);
        printf("Title: %s\n", c.title);
        printf("Victim: %s\n", c.victim);
        printf("Perpetrator: %s\n", c.perpetrator);
        printf("Year: %d\n\n", c.year);
    }

    // Close the file
    fclose(fp);

    return 0;
}
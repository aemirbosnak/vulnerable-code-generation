//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[50];
    int age;
    char gender[10];
} Person;

int main(){
    FILE *fp;
    char filename[50];
    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error opening file!\n");
        return 0;
    }

    char line[1024];
    char *token;
    int row = 0, col = 0;
    Person people[100];

    while(fgets(line, 1024, fp)){
        token = strtok(line, ",");
        while(token != NULL){
            if(col == 0){
                strcpy(people[row].name, token);
            }
            else if(col == 1){
                people[row].age = atoi(token);
            }
            else if(col == 2){
                strcpy(people[row].gender, token);
            }
            token = strtok(NULL, ",");
            col++;
        }
        row++;
        col = 0;
    }

    fclose(fp);

    printf("Name\tAge\tGender\n");
    for(int i=0; i<row; i++){
        printf("%s\t%d\t%s\n", people[i].name, people[i].age, people[i].gender);
    }

    return 0;
}
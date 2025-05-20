//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 100

typedef struct{
    char name[20];
    int age;
    char email[40];
} Person;

Person* read_csv(char *file_name, int *size);

int main(){
    int size;
    char file_name[50];
    printf("Enter the name of the CSV file to read: ");
    scanf("%s", file_name);
    Person *people = read_csv(file_name, &size);
    if(people != NULL){
        printf("The following people were read from the CSV file:\n");
        for(int i = 0; i < size; i++){
            printf("%s, %d, %s\n", people[i].name, people[i].age, people[i].email);
        }
    }
    free(people);
    return 0;
}

Person* read_csv(char *file_name, int *size){
    FILE *file = fopen(file_name, "r");
    if(file == NULL){
        printf("Error: Could not open file %s\n", file_name);
        return NULL;
    }

    char line[LINE_SIZE];
    char *token;
    int count = 0;
    while(fgets(line, LINE_SIZE, file)){
        count++;
    }
    *size = count - 1;
    rewind(file);
    
    Person *people = malloc(*size * sizeof(Person));
    
    // Ignore header line
    fgets(line, LINE_SIZE, file);
    int i = 0;
    while(fgets(line, LINE_SIZE, file)){
        token = strtok(line, ",");
        strcpy(people[i].name, token);
        token = strtok(NULL, ",");
        people[i].age = atoi(token);
        token = strtok(NULL, ",");
        strcpy(people[i].email, token);
        i++;
    }

    fclose(file);

    return people;
}
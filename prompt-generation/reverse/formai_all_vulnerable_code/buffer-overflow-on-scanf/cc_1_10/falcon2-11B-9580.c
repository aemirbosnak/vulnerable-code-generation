//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to store data
struct Data
{
    int id;
    char name[50];
    float score;
};

// Function to add data to the database
void addData(struct Data* data)
{
    FILE* file = fopen("database.txt", "a");
    if(file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(file, "%d,%s,%f\n", data->id, data->name, data->score);
    fclose(file);
}

// Function to retrieve data from the database
void retrieveData(struct Data* data)
{
    FILE* file = fopen("database.txt", "r");
    if(file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    char line[100];
    while(fgets(line, sizeof(line), file)!= NULL)
    {
        char* tokens[3];
        sscanf(line, "%d,%s,%f", &data->id, data->name, &data->score);
    }
    fclose(file);
}

int main()
{
    struct Data data;
    printf("Enter student ID: ");
    scanf("%d", &data.id);
    printf("Enter student name: ");
    scanf("%s", data.name);
    printf("Enter student score: ");
    scanf("%f", &data.score);
    addData(&data);
    retrieveData(&data);
    return 0;
}
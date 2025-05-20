//FormAI DATASET v1.0 Category: Database Indexing System ; Style: active
#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

/*Structure of a record*/ 
struct record
{
    int id;
    char name[50];
    float marks;
};

/*Structure of a node in the indexing list*/
struct node
{
    int key; 
    int locationPointer;  
    struct node *next; 
};

/*Function to create a node*/
struct node *createNode(int key, int locationPointer) 
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node)); 
    newNode->key = key;
    newNode->locationPointer = locationPointer;
    newNode->next = NULL; 
    return newNode; 
}

/*Function to insert a node into the indexing list*/
void insert(struct node **head, int key, int locationPointer)
{
    struct node *current = *head;
    struct node *newNode = createNode(key, locationPointer); 

    if(*head == NULL || (*head)->key >= key)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else 
    {
        while(current->next!=NULL && current->next->key < key)
        {
            current = current->next; 
        }
        newNode->next = current->next; 
        current->next = newNode; 
    }
}

/*Function to search a record based on id*/
void searchRecord(FILE *fp, struct node *head, int id)
{
    struct node *current = head;
    int locationPointer = -1;
    
    while(current!=NULL)
    {
        if(current->key == id)
        {
            locationPointer = current->locationPointer;
            break;
        }
        current = current->next; 
    }

    if(locationPointer == -1)
    {
        printf("Record with id %d not found in the database.\n", id);
    }
    else 
    {
        fseek(fp, locationPointer*sizeof(struct record), SEEK_SET);
        struct record temp;
        fread(&temp, sizeof(struct record), 1, fp);
        printf("Record found in database:\n");
        printf("ID: %d\t Name: %s\t Marks: %0.2f\n", temp.id, temp.name, temp.marks);
    }
}

/*Main function*/
int main()
{
    struct record student;
    FILE *fp; 
    int choice, id, locationPointer;
    struct node *head = NULL;

    /*Open the database file*/
    fp = fopen("database.bin", "rb+");
    if(fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    /*Read all records from the file and insert into the indexing list*/
    while(fread(&student, sizeof(struct record), 1, fp))
    {
        locationPointer = ftell(fp) - sizeof(struct record);
        insert(&head, student.id, locationPointer);
    }

    /*Display menu*/
    printf("Menu:\n");
    printf("1. Search for a record\n");
    printf("2. Exit\n");

    /*Get user choice*/
    printf("Enter your choice: ");
    scanf("%d", &choice);

    /*Process user choice*/
    switch(choice)
    {
        case 1: 
            printf("Enter ID to search: ");
            scanf("%d", &id);
            searchRecord(fp, head, id);
            break;
        case 2: 
            printf("Exiting program.\n");
            break;
        default: 
            printf("Invalid choice.\n");
            break;
    }

    /*Close the file*/
    fclose(fp);

    return 0;
}
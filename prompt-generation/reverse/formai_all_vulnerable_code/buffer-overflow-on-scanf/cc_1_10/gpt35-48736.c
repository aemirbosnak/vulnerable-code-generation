//FormAI DATASET v1.0 Category: Database Indexing System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    int rollNo;
    char name[50];
    int age;
    char address[100];
};

struct record
{
    int index;
    struct student data;
};

void add_record(struct record* records, int* index)
{
    printf("Enter Roll No: ");
    scanf("%d", &records[*index].data.rollNo);
    printf("Enter Name: ");
    scanf("%s", &records[*index].data.name);
    printf("Enter Age: ");
    scanf("%d", &records[*index].data.age);
    printf("Enter address: ");
    scanf("%s", &records[*index].data.address);
    records[*index].index = *index;
    (*index)++;
}

int search_record_by_rollNo(struct record* records, int index, int rollNo)
{
    int i;
    for(i=0; i<index; i++)
    {
        if(records[i].data.rollNo == rollNo)
            return i;
    }
    return -1;
}

int compare_record(const void* a, const void* b)
{
    return (((struct record*)a)->data.rollNo - ((struct record*)b)->data.rollNo);
}

void sort_records_by_rollNo(struct record* records, int index)
{
    qsort(records, index, sizeof(struct record), compare_record);
}

int main()
{
    struct record records[100];
    int index = 0, choice, rollNo, i, recordIndex;
    
    while(1)
    {
        printf("Enter your choice:\n");
        printf("1. Add Record\n");
        printf("2. Search Record by Roll No\n");
        printf("3. Sort Records by Roll No\n");
        printf("4. Exit\n");
        
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: add_record(records, &index);
                    break;
                    
            case 2: printf("Enter Roll No to search: ");
                    scanf("%d", &rollNo);
                    recordIndex = search_record_by_rollNo(records, index, rollNo);
                    if(recordIndex == -1)
                        printf("Record not found\n");
                    else
                    {
                        printf("Roll No: %d\n", records[recordIndex].data.rollNo);
                        printf("Name: %s\n", records[recordIndex].data.name);
                        printf("Age: %d\n", records[recordIndex].data.age);
                        printf("Address: %s\n", records[recordIndex].data.address);
                    }
                    break;
                    
            case 3: sort_records_by_rollNo(records, index);
                    printf("Records sorted by Roll No.\n");
                    for(i=0;i<index;i++)
                    {
                        printf("Index: %d Roll No: %d Name: %s Age: %d Address: %s\n", records[i].index, records[i].data.rollNo, records[i].data.name, records[i].data.age, records[i].data.address);
                    }
                    break;
                    
            case 4: exit(0);
            
            default: printf("Invalid choice.\n");
        }
    }
    
    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Struct to store the database
struct db{
    char name[50];
    int age;
};

int main()
{
    struct db *db;
    int choice = 0, flag = 0;

    // Allocate memory for the database
    db = (struct db *)malloc(sizeof(struct db));

    // Loop until the user wants to exit
    while(choice!= 4)
    {
        printf("1. Add a record\n2. Search a record\n3. Delete a record\n4. Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter the details: ");
                scanf("%s %d", db->name, &db->age);
                break;
            case 2:
                printf("Enter the name to search: ");
                scanf("%s", db->name);
                flag = 0;
                for(int i = 0; i < sizeof(db)/sizeof(db->name); i++)
                {
                    if(strcmp(db->name, db[i].name) == 0)
                    {
                        flag = 1;
                        printf("Record found\n");
                        break;
                    }
                }
                if(flag == 0)
                {
                    printf("Record not found\n");
                }
                break;
            case 3:
                printf("Enter the name to delete: ");
                scanf("%s", db->name);
                for(int i = 0; i < sizeof(db)/sizeof(db->name); i++)
                {
                    if(strcmp(db->name, db[i].name) == 0)
                    {
                        strcpy(db[i].name, "");
                        free(db[i].age);
                        free(db);
                        db = (struct db *)malloc(sizeof(struct db));
                        printf("Record deleted\n");
                        break;
                    }
                }
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    free(db);
    return 0;
}
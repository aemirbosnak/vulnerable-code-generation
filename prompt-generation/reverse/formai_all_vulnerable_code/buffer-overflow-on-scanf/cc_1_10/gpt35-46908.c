//FormAI DATASET v1.0 Category: Database simulation ; Style: bold
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to define a record in the database
struct database_record
{
    int id;
    char name[30];
    float price;
};

//Function to print the records in the database
void print_database(struct database_record *db, int len)
{
    printf("ID \tName \tPrice \n");
    for(int i=0;i<len;i++)
    {
        printf("%d \t%s \t%.2f \n", db[i].id, db[i].name, db[i].price);
    }
    printf("\n");
}

int main()
{
    //Prompt the user for the number of records to be stored in the database
    printf("Enter the number of records to be stored in the database: ");
    int len;
    scanf("%d", &len);
    
    //Allocate memory for the database
    struct database_record *db = (struct database_record*)malloc(len*sizeof(struct database_record));
    
    //Prompt the user to enter details of the records to be stored in the database
    for(int i=0;i<len;i++)
    {
        printf("\nEnter details of record %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &db[i].id);
        printf("Name: ");
        scanf("%s", db[i].name);
        printf("Price: ");
        scanf("%f", &db[i].price);
    }
    
    //Print the records in the database
    printf("Database: \n");
    print_database(db, len);
    
    //Prompt the user to search for a record in the database
    printf("Enter the ID of the record to be searched: ");
    int search_id;
    scanf("%d", &search_id);
    int found = 0;
    
    //Search for the record in the database
    for(int i=0;i<len;i++)
    {
        if(db[i].id == search_id)
        {
            printf("\nThe record with ID %d has been found.\n", search_id);
            printf("Details: Name - %s, Price - %.2f\n", db[i].name, db[i].price);
            found = 1;
            break;
        }
    }
    
    //If the record is not found, inform the user
    if(!found)
    {
        printf("\nThe record with ID %d does not exist in the database.\n", search_id);
    }
    
    //Prompt the user to update a record in the database
    printf("\nEnter the ID of the record to be updated: ");
    int update_id;
    scanf("%d", &update_id);
    
    //Search for the record in the database
    for(int i=0;i<len;i++)
    {
        if(db[i].id == update_id)
        {
            printf("\nThe record with ID %d has been found.\n", update_id);
            printf("Enter the updated details:\n");
            printf("Name: ");
            scanf("%s", db[i].name);
            printf("Price: ");
            scanf("%f", &db[i].price);
            printf("\nThe record with ID %d has been updated.\n", update_id);
            break;
        }
    }
    
    //Print the updated database
    printf("Updated Database: \n");
    print_database(db, len);
    
    //Prompt the user to delete a record from the database
    printf("Enter the ID of the record to be deleted: ");
    int delete_id;
    scanf("%d", &delete_id);
    
    //Search for the record in the database
    for(int i=0;i<len;i++)
    {
        if(db[i].id == delete_id)
        {
            printf("\nThe record with ID %d has been deleted.\n", delete_id);
            //Shift the remaining records to fill the gap created by the deleted record
            for(int j=i;j<len-1;j++)
            {
                db[j] = db[j+1];
            }
            len--;
            break;
        }
    }
    
    //Print the updated database
    printf("Updated Database: \n");
    print_database(db, len);
    
    //Free the memory allocated for the database
    free(db);
    
    return 0;
}
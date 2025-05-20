//FormAI DATASET v1.0 Category: Database Indexing System ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

// Defining Data type for index
typedef struct {
    char keyword[20]; //Keyword to be indexed
    int indexPos; //Index position of keyword in database
} Index;

// Defining Data type for the database
typedef struct {
    char content[100]; //Content of the database
} Database;

// Function prototypes
void createIndex(Database[], Index[], int);
int searchIndex(char[], Index[], int);
void displayIndex(Index[], int);

int main(){
    Database data[MAX];
    Index index[MAX];
    int dataSize, indexSize, choice, result;
    char keyword[20];

    printf("Enter the number of records in the Database: ");
    scanf("%d", &dataSize);

    // Reading database content from user
    printf("\nEnter the content of the database:\n");
    for(int i=0; i<dataSize; i++){
        printf("\nRecord %d:\n", i+1);
        getchar();
        fgets(data[i].content, 100, stdin);
    }

    // Creating index for database
    createIndex(data, index, dataSize);

    // Determining size of the index
    indexSize = sizeof(index) / sizeof(index[0]);

    do{
        printf("\n*** DATABASE INDEXING SYSTEM ***\n");
        printf("1. Search for a keyword\n");
        printf("2. Display entire index\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the keyword to search: ");
                scanf("%s", keyword);

                result = searchIndex(keyword, index, indexSize);

                if(result == -1){
                    printf("\nThe keyword '%s' does not exist in the database\n", keyword);
                }else{
                    printf("\nThe keyword '%s' is found at record %d in the database\n", keyword, index[result].indexPos);
                }
                break;

            case 2:
                displayIndex(index, indexSize);
                break;

            case 3:
                printf("\nExiting...");
                exit(0);
                break;

            default:
                printf("\nInvalid choice. Please try again.");
                break;
        }

    }while(1);

    return 0;
}

// Function to create index for database
void createIndex(Database data[], Index index[], int dataSize){
    int i, j, k, l, m;
    char keyword[20];

    // Traversing through each record of the Database
    for(i=0, k=0; i<dataSize; i++){
        // Traversing through each word of the record
        for(j=0, l=0; j<strlen(data[i].content); j++){

            // If a space or a newline character is encountered
            if(data[i].content[j]==' ' || data[i].content[j]=='\n'){
                keyword[l] = '\0';

                // Storing the index position along with the corresponding keyword
                index[k].indexPos = i+1;
                strcpy(index[k].keyword, keyword);
                k++;
                l=0;
            }else{
                keyword[l] = data[i].content[j];
                l++;
            }
        }
    }

    // Sorting the index based on keywords using bubble sort
    Index temp;
    for(i=0; i<k; i++){
        for(j=0; j<k-i-1; j++){
            if(strcmp(index[j].keyword, index[j+1].keyword)>0){
                temp = index[j];
                index[j] = index[j+1];
                index[j+1] = temp;
            }
        }
    }

    printf("\nIndex created successfully for the given database\n");
    printf("Press any key to continue...");
    getchar();
}

// Function to search for a keyword in the index
int searchIndex(char keyword[], Index index[], int indexSize){
    int mid, low = 0, high = indexSize - 1;

    while (low <= high){
        mid = (low + high) / 2;
        if (strcmp(index[mid].keyword, keyword) == 0){
            return mid;
        }else if (strcmp(index[mid].keyword, keyword) < 0){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return -1;  // If keyword is not found
}

// Function to display entire index
void displayIndex(Index index[], int indexSize){
    printf("\nKeyword            Index Position");
    printf("\n---------------------------------\n");

    for(int i=0; i<indexSize; i++){
        printf("%-20s %d\n", index[i].keyword, index[i].indexPos);
    }

    printf("\nPress any key to continue...");
    getchar();
    getchar();
}
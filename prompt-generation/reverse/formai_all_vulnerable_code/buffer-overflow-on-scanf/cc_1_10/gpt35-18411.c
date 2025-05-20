//FormAI DATASET v1.0 Category: Database Indexing System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LEN 20
#define MAX_CITY_LEN 15
#define MAX_ENTRIES 1000

typedef struct{
    char name[MAX_NAME_LEN];
    char city[MAX_CITY_LEN];
    int age;
    long phone_num;
} Record;

typedef struct{
    char name[MAX_NAME_LEN];
    int record_index;
} Index;

void print_records(Record records[], int num_records){
    printf("\nName\tCity\tAge\tPhone\n");
    printf("------------------------------------------------\n");
    for(int i=0; i<num_records; i++){
        printf("%s\t%s\t%d\t%ld\n", records[i].name, records[i].city, records[i].age, records[i].phone_num);
    }
    printf("------------------------------------------------\n");
}

void print_index(Index index[], int num_records){
    printf("\n");
    for(int i=0; i<num_records; i++){
        printf("%s\t%d\n", index[i].name, index[i].record_index);
    }
}

void sort_index(Index index[], int num_records){
    Index temp;
    for(int i=0; i<num_records; i++){
        for(int j=i+1; j<num_records; j++){
            if(strcmp(index[i].name, index[j].name) > 0){
                temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }
}

int binary_search(Index index[], int num_records, char search_name[]){
    int starting_index = 0;
    int ending_index = num_records - 1;
    int middle_index;

    while(starting_index <= ending_index){

        middle_index = (starting_index + ending_index)/2;

        if(strcmp(search_name, index[middle_index].name) == 0){
            return index[middle_index].record_index;
        }
        else if(strcmp(search_name, index[middle_index].name) > 0){
            starting_index = middle_index + 1;
        }
        else{
            ending_index = middle_index - 1;
        }

    }
    return -1;
}

int main(){

    Record records[MAX_ENTRIES];
    Index index[MAX_ENTRIES];
    int num_records = 0;
    char search_name[MAX_NAME_LEN];

    while(1){

        printf("\nMenu:\n1. Add Record\n2. Search by Name\n3. Print Records\n4. Print Index\n5. Exit\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("\nEnter the name: ");
                scanf("%s", records[num_records].name);
                printf("Enter the city: ");
                scanf("%s", records[num_records].city);
                printf("Enter the age: ");
                scanf("%d", &records[num_records].age);
                printf("Enter the phone number: ");
                scanf("%ld", &records[num_records].phone_num);

                // Add the new record to the index
                strncpy(index[num_records].name, records[num_records].name, MAX_NAME_LEN);
                index[num_records].record_index = num_records;

                // Sort the index
                sort_index(index, num_records+1);

                num_records++;
                printf("\nRecord added successfully!\n");
                break;

            case 2:
                printf("\nEnter the name to search: ");
                scanf("%s", search_name);

                // Do binary search on the sorted index to find the record
                int found_index = binary_search(index, num_records, search_name);

                if(found_index >= 0){
                    printf("\nRecord found!\nName: %s\nCity: %s\nAge: %d\nPhone: %ld\n", 
                            records[found_index].name, records[found_index].city, records[found_index].age, records[found_index].phone_num);
                }
                else{
                    printf("\nRecord not found!\n");
                }
                break;

            case 3:
                print_records(records, num_records);
                break;

            case 4:
                print_index(index, num_records);
                break;

            case 5:
                printf("\nExiting...\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice!\n");
                break;

        }

    }

    return 0;
}
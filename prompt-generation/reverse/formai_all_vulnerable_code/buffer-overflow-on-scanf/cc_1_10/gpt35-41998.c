//FormAI DATASET v1.0 Category: Digital Diary ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ENTRIES 100

//Entry structure
struct Entry{
    char date[11];  //Format: dd/mm/yyyy
    char title[50]; 
    char content[500];
};

//Main function
int main(){
    
    //Array to store entries
    struct Entry diary[MAX_ENTRIES];
    
    //Index variable to keep track of number of entries
    int num_entries = 0;
    
    //Welcome message
    printf("Welcome to your Digital Diary!\n");
    
    //Menu options
    while(1){
        
        printf("\n1. Add entry\n");
        printf("2. View entry\n");
        printf("3. Exit\n");
        printf("Please enter your choice (1-3): ");
        
        int option;
        scanf("%d",&option);
        
        //Add Entry option
        if(option == 1){
            
            if(num_entries == MAX_ENTRIES){
                printf("\nSorry, you have reached the maximum number of entries.\n");
                continue;
            }
            
            printf("\nEnter the date (dd/mm/yyyy): ");
            scanf(" %[^\n]%*c", diary[num_entries].date);
            
            printf("Enter the title: ");
            scanf(" %[^\n]%*c", diary[num_entries].title);
            
            printf("Enter the content: ");
            scanf(" %[^\n]%*c", diary[num_entries].content);
            
            num_entries++;
            
            printf("\nEntry added successfully!\n");
            
        }
        //View entry option
        else if(option == 2){
            
            if(num_entries == 0){
                printf("\nNo entries found!\n");
                continue;
            }
            
            printf("\nEnter the date (dd/mm/yyyy): ");
            char search_date[11];
            scanf(" %[^\n]%*c", search_date);
            
            int found = 0;
            
            for(int i=0;i<num_entries;i++){
                if(strcmp(diary[i].date,search_date) == 0){
                    found = 1;
                    printf("\nDate: %s\n",diary[i].date);
                    printf("Title: %s\n",diary[i].title);
                    printf("Content: %s\n",diary[i].content);
                    break;
                }
            }
            
            if(!found)
                printf("\nNo entry found for the given date!\n");
            
        }
        //Exit option
        else if(option == 3){
            printf("\nExiting Digital Diary...\n");
            break;
        }
        //Invalid option
        else{
            printf("\nInvalid option! Please try again.\n");
            continue;
        }
        
    }
    
    return 0;
}
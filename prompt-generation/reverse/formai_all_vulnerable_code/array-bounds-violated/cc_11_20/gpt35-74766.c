//FormAI DATASET v1.0 Category: Syntax parsing ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char name[20];
    int lineNumber;
    struct Node* next;
};

int main(){
    char input[100];
    struct Node* start=NULL;
    struct Node* end=NULL;

    while(1){
        printf("Enter C syntax: ");
        fgets(input, sizeof(input), stdin);

        if(strcmp(input, "exit\n")==0){
            break;
        }

        if(input[strlen(input)-1]!='\n'){
            printf("Error: Input is too long. Maximum input length is 99 characters.\n");
            scanf("%*[^\n]"); // clears input buffer
            continue;
        }

        input[strlen(input)-1]='\0'; //removing newline

        char* token= strtok(input, " ");

        while(token!=NULL){
            struct Node* newNode= (struct Node*) malloc(sizeof(struct Node));

            if(newNode==NULL){
                printf("Memory allocation for a new node failed.");
                exit(1);
            }

            strcpy(newNode->name, token);
            newNode->lineNumber=1;

            if(start==NULL){
                start=newNode;
                end=newNode;
                newNode->next=NULL;
            }
            else{
                struct Node* current=end;
                int found=0;
                while(current!=NULL){
                    if(strcmp(current->name, newNode->name)==0){
                        current->lineNumber++;
                        found=1;
                        free(newNode);
                        break;
                    }
                    current=current->next;
                }

                if(found==0){
                    end->next= newNode;
                    end=newNode;
                }
            }

            token = strtok(NULL, " ");
        }

        printf("Syntax Parsed.\n");
    }

    printf("\n\nSyntax Frequency Table:\n\n");
    if(start==NULL){
        printf("No syntax entered.");
    }
    else{
        printf("Syntax Name  | Line Count\n");
        printf("------------------------\n");

        struct Node* current= start;
        while(current!=NULL){
            printf("%-12s | %-8d\n", current->name, current->lineNumber);
            current= current->next;
        }
    }

    struct Node* temp;
    while(start!=NULL){
        temp=start;
        start=start->next;
        free(temp);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Phone Book ; Style: retro
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct phonebook {
    char name[50], phone[20];
};

int main(){
    int n, ch, i, flag = 0;
    printf("Enter the number of entries: ");
    scanf("%d", &n);
    struct phonebook *pb = (struct phonebook *)malloc(n * sizeof(struct phonebook));
    for(i=0; i<n; i++){
        printf("Enter name of person %d: ", i+1);
        scanf("%s", (pb+i)->name);
        printf("Enter phone number of person %d: ", i+1);
        scanf("%s", (pb+i)->phone);
    }
    
    while(1){
        printf("\n\n1. Search by name\n2. Search by phone number\n3. Print all\n4. Exit\nEnter Choice: ");
        scanf("%d", &ch);
        if(ch == 1){ //Search by Name
            char search_name[50];
            printf("Enter name to search: ");
            scanf("%s", search_name);
            flag = 0;
            for(i=0;i<n;i++){
                if(strcmp((pb+i)->name, search_name) == 0){
                    flag = 1;
                    printf("Name: %s\nPhone: %s\n", (pb+i)->name, (pb+i)->phone);
                    break;
                }
            }
            if(!flag)
                printf("Entry not found!\n");
        }
        else if(ch == 2){ //Search by Phone
            char search_phone[20];
            printf("Enter phone to search: ");
            scanf("%s", search_phone);
            flag = 0;
            for(i=0;i<n;i++){
                if(strcmp((pb+i)->phone, search_phone) == 0){
                    flag = 1;
                    printf("Name: %s\nPhone: %s\n", (pb+i)->name, (pb+i)->phone);
                    break;
                }
            }
            if(!flag)
                printf("Entry not found!\n");
        }
        else if(ch == 3){ //Print All
            for(i=0;i<n;i++){
                printf("Name: %s\nPhone: %s\n\n", (pb+i)->name, (pb+i)->phone);
            }
        }
        else if(ch == 4){ //Exit
            free(pb);
            printf("Goodbye!\n");
            return 0;
        }
        else { //Invalid Option
            printf("Invalid Option!\n");
        }
    }
    return 0;
}
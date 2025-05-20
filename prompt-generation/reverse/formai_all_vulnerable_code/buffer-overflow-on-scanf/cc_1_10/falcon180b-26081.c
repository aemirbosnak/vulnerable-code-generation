//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ENTRIES 100

struct entry{
    char name[50];
    char phone[15];
};

void add_entry(struct entry *directory, int index, char *name, char *phone){
    strcpy(directory[index].name, name);
    strcpy(directory[index].phone, phone);
}

int search_entry(struct entry *directory, int index, char *name){
    if(strcmp(directory[index].name, name) == 0){
        return index;
    }
    else{
        return -1;
    }
}

void delete_entry(struct entry *directory, int index){
    directory[index].name[0] = '\0';
    directory[index].phone[0] = '\0';
}

void display_entries(struct entry *directory, int num_entries){
    printf("Name\tPhone\n");
    for(int i=0; i<num_entries; i++){
        printf("%s\t%s\n", directory[i].name, directory[i].phone);
    }
}

int main(){
    struct entry directory[MAX_ENTRIES];
    int num_entries = 0;
    char name[50], phone[15];

    printf("Enter name and phone number in the format 'Name Phone':\n");
    while(scanf("%s %s", name, phone) == 2){
        add_entry(directory, num_entries, name, phone);
        num_entries++;
    }

    int choice;
    do{
        printf("\nPhone Book Menu:\n");
        printf("1. Search for an entry\n");
        printf("2. Add an entry\n");
        printf("3. Delete an entry\n");
        printf("4. Display all entries\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter name to search: ");
                scanf("%s", name);
                int index = search_entry(directory, num_entries, name);
                if(index!= -1){
                    printf("%s\t%s\n", directory[index].name, directory[index].phone);
                }
                else{
                    printf("Entry not found.\n");
                }
                break;
            case 2:
                printf("Enter name and phone number in the format 'Name Phone':\n");
                scanf("%s %s", name, phone);
                add_entry(directory, num_entries, name, phone);
                num_entries++;
                break;
            case 3:
                printf("Enter name to delete: ");
                scanf("%s", name);
                index = search_entry(directory, num_entries, name);
                if(index!= -1){
                    delete_entry(directory, index);
                    num_entries--;
                }
                else{
                    printf("Entry not found.\n");
                }
                break;
            case 4:
                display_entries(directory, num_entries);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }while(1);

    return 0;
}
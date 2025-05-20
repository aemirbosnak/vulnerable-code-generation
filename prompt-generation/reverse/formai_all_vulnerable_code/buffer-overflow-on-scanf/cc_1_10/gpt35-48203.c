//FormAI DATASET v1.0 Category: Mailing list manager ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EMAIL_LENGTH 50 //max length of an email
#define MAX_LIST_NAME_LENGTH 20 //max length of list name
#define MAX_EMAILS_PER_LIST 100 //max number of emails in a list

/*Structure to store the emails*/
struct email_list{
    char email[MAX_EMAIL_LENGTH];
};

/*Structure to store the list name and its emails*/
struct mailing_list{
    char list_name[MAX_LIST_NAME_LENGTH];
    struct email_list list[MAX_EMAILS_PER_LIST];
    int num_emails;
};

/*Function to add a new email to a mailing list*/
void add_email(struct mailing_list *list, char *email){
    /*Check if the email already exists in the list*/
    for(int i=0;i<list->num_emails;i++){
        if(strcmp(list->list[i].email, email) == 0){
            printf("\n%s already exists in %s mailing list.", email, list->list_name);
            return;
        }
    }
    /*Email doesn't exist in the mailing list*/
    /*Add the new email to the list*/
    struct email_list new_email;
    strcpy(new_email.email, email);
    list->list[list->num_emails] = new_email;
    list->num_emails++;
    printf("\n%s added to %s mailing list.", email, list->list_name);
}

/*Function to remove an email from a mailing list*/
void remove_email(struct mailing_list *list, char *email){
    /*Check if the email exists in the list*/
    int found = 0;
    for(int i=0;i<list->num_emails;i++){
        if(strcmp(list->list[i].email, email) == 0){
            found = 1;
            /*Shift all elements to the left*/
            for(int j=i;j<list->num_emails-1;j++){
                list->list[j] = list->list[j+1];
            }
            list->num_emails--;
            printf("\n%s removed from %s mailing list.", email, list->list_name);
            break;
        }
    }
    /*Email doesn't exist in the mailing list*/
    if(!found){
        printf("\n%s does not exist in %s mailing list.", email, list->list_name);
    }
}

/*Function to print a mailing list*/
void print_list(struct mailing_list *list){
    printf("\n%s Mailing List", list->list_name);
    for(int i=0;i<list->num_emails;i++){
        printf("\n%s", list->list[i].email);
    }
}

int main(){
    /*Create an array of mailing lists*/
    struct mailing_list lists[10];
    int num_lists = 0;

    /*Configurable menu options*/
    int option = 0;
    do{
        printf("\n\nMailing List Manager\n\n");
        printf("1. Create a new mailing list\n");
        printf("2. Add an email to a mailing list\n");
        printf("3. Remove an email from a mailing list\n");
        printf("4. Print a mailing list\n");
        printf("0. Exit\n\n");
        printf("Enter an option: ");
        scanf("%d", &option);

        if(option == 1){
            /*Option 1: Create a new mailing list*/
            printf("\nEnter a name for the new mailing list (max %d characters): ", MAX_LIST_NAME_LENGTH);
            char name[MAX_LIST_NAME_LENGTH];
            scanf("%s", name);
            /*Check if the mailing list already exists*/
            for(int i=0;i<num_lists;i++){
                if(strcmp(lists[i].list_name, name) == 0){
                    printf("\n%s mailing list already exists.", name);
                    continue;
                }
            }
            /*Create a new mailing list*/
            struct mailing_list new_list;
            strcpy(new_list.list_name, name);
            new_list.num_emails = 0;
            lists[num_lists] = new_list;
            num_lists++;
            printf("\n%s mailing list created successfully.", name);
        }else if(option == 2){
            /*Option 2: Add an email to a mailing list*/
            if(num_lists == 0){
                printf("\nNo mailing lists found. Please create a new mailing list first.");
                continue;
            }
            printf("\nSelect a mailing list to add an email to:");
            for(int i=0;i<num_lists;i++){
                printf("\n%d. %s", i+1,lists[i].list_name);
            }
            int list_num = 0;
            scanf("%d", &list_num);
            if(list_num < 1 || list_num > num_lists){
                printf("\nInvalid list number.");
                continue;
            }
            printf("\nEnter an email to add to %s mailing list (max %d characters): ", lists[list_num-1].list_name, MAX_EMAIL_LENGTH);
            char email[MAX_EMAIL_LENGTH];
            scanf("%s", email);
            add_email(&lists[list_num-1], email);
        }else if(option == 3){
            /*Option 3: Remove an email from a mailing list*/
            if(num_lists == 0){
                printf("\nNo mailing lists found. Please create a new mailing list first.");
                continue;
            }
            printf("\nSelect a mailing list to remove an email from:");
            for(int i=0;i<num_lists;i++){
                printf("\n%d. %s", i+1,lists[i].list_name);
            }
            int list_num = 0;
            scanf("%d", &list_num);
            if(list_num < 1 || list_num > num_lists){
                printf("\nInvalid list number.");
                continue;
            }
            printf("\nEnter an email to remove from %s mailing list: ", lists[list_num-1].list_name);
            char email[MAX_EMAIL_LENGTH];
            scanf("%s", email);
            remove_email(&lists[list_num-1], email);
        }else if(option == 4){
            /*Option 4: Print a mailing list*/
            if(num_lists == 0){
                printf("\nNo mailing lists found. Please create a new mailing list first.");
                continue;
            }
            printf("\nSelect a mailing list to print:");
            for(int i=0;i<num_lists;i++){
                printf("\n%d. %s", i+1,lists[i].list_name);
            }
            int list_num = 0;
            scanf("%d", &list_num);
            if(list_num < 1 || list_num > num_lists){
                printf("\nInvalid list number.");
                continue;
            }
            print_list(&lists[list_num-1]);
        }

    }while(option != 0);

    return 0;
}
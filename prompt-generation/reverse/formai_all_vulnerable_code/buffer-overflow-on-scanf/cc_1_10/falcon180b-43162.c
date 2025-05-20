//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_MEMBERS 100

struct member{
    char name[50];
    char email[100];
};

struct member mailing_list[MAX_MEMBERS];
int member_count = 0;

void add_member(){
    printf("Enter the name of the member: ");
    scanf("%s", mailing_list[member_count].name);
    printf("Enter the email of the member: ");
    scanf("%s", mailing_list[member_count].email);
    member_count++;
    printf("\nMember added successfully!\n");
}

void delete_member(){
    int index;
    printf("Enter the index of the member you want to delete: ");
    scanf("%d", &index);
    if(index >= 0 && index < member_count){
        for(int i=index; i<member_count-1; i++){
            strcpy(mailing_list[i].name, mailing_list[i+1].name);
            strcpy(mailing_list[i].email, mailing_list[i+1].email);
        }
        member_count--;
        printf("\nMember deleted successfully!\n");
    }
    else{
        printf("\nInvalid index! Please try again.\n");
    }
}

void view_members(){
    printf("\nName\tEmail\n");
    for(int i=0; i<member_count; i++){
        printf("%s\t%s\n", mailing_list[i].name, mailing_list[i].email);
    }
}

void send_mail(){
    printf("\nEnter the subject of the mail: ");
    char subject[100];
    scanf("%s", subject);
    printf("Enter the body of the mail: ");
    char body[500];
    scanf("%[^\n]", body);
    for(int i=0; i<member_count; i++){
        sprintf(mailing_list[i].email, "%s", mailing_list[i].email);
        system(mailing_list[i].email);
    }
    printf("\nMail sent successfully!\n");
}

int main(){
    int choice;
    do{
        printf("\n1. Add member\n2. Delete member\n3. View members\n4. Send mail\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_member();
                break;
            case 2:
                delete_member();
                break;
            case 3:
                view_members();
                break;
            case 4:
                send_mail();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }while(1);
    return 0;
}
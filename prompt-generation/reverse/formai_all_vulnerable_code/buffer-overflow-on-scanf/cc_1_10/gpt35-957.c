//FormAI DATASET v1.0 Category: Database Indexing System ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

struct member {
    int id;
    char name[50];
    char email[50];
    char phone[20];
};

struct index {
    int id;
    int pos;
};

void create(struct member[], struct index[], int*);
void search(struct member[], struct index[], int*);
void modify(struct member[], struct index[], int*);
void display(struct member[], struct index[], int*);

int main() {
    struct member mem[MAX];
    struct index ind[MAX];
    int n=0, ch;

    while(1) {
        printf("1-Create 2-Search 3-Modify 4-Display 5-Exit: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                create(mem, ind, &n);
                break;
            case 2:
                search(mem, ind, &n);
                break;
            case 3:
                modify(mem, ind, &n);
                break;
            case 4:
                display(mem, ind, &n);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

void create(struct member mem[], struct index ind[], int *n) {
    int i, id, flag=0;
    char name[50];
    printf("Enter member id: ");
    scanf("%d", &id);
    for(i=0; i<*n; i++) {
        if(mem[i].id == id) {
            flag = 1;
            break;
        }
    }
    if(flag == 1) {
        printf("Error: ID already exists!\n");
        return;
    }
    mem[*n].id = id;
    printf("Enter member name: ");
    scanf("%s", mem[*n].name);
    printf("Enter email address: ");
    scanf("%s", mem[*n].email);
    printf("Enter phone number: ");
    scanf("%s", mem[*n].phone);
    ind[*n].id = id;
    ind[*n].pos = *n;
    *n += 1;
    printf("Member successfully added.\n");
}

void search(struct member mem[], struct index ind[], int *n) {
    int i, j, id, found=0;
    printf("Enter member id to search: ");
    scanf("%d", &id);
    for(i=0; i<*n; i++) {
        if(mem[i].id == id) {
            j = ind[i].pos;
            printf("Member ID\tName\tEmail\tPhone\n");
            printf("------------------------------------------------\n");
            printf("%d\t\t%s\t%s\t%s\n", mem[j].id, mem[j].name, mem[j].email, mem[j].phone);
            found = 1;
            break;
        }
    }
    if(found == 0) {
        printf("Member not found.\n");
    }
}

void modify(struct member mem[], struct index ind[], int *n) {
    int i, j, id, ch;
    char email[50], phone[20];
    printf("Enter member id to modify: ");
    scanf("%d", &id);
    for(i=0; i<*n; i++) {
        if(mem[i].id == id) {
            j = ind[i].pos;
            printf("Member ID\tName\tEmail\tPhone\n");
            printf("------------------------------------------------\n");
            printf("%d\t\t%s\t%s\t%s\n", mem[j].id, mem[j].name, mem[j].email, mem[j].phone);
            printf("1-Email 2-Phone: ");
            scanf("%d", &ch);
            switch(ch) {
                case 1:
                    printf("Enter new email address: ");
                    scanf("%s", email);
                    strcpy(mem[j].email, email);
                    printf("Email address updated successfully!\n");
                    break;
                case 2:
                    printf("Enter new phone number: ");
                    scanf("%s", phone);
                    strcpy(mem[j].phone, phone);
                    printf("Phone number updated successfully!\n");
                    break;
                default:
                    printf("Invalid choice.\n");
            } 
            break;
        }
    }
    if(i == *n) {
        printf("Member not found.\n");
    }
}

void display(struct member mem[], struct index ind[], int *n) {
    int i, j;
    printf("Member ID\tName\tEmail\tPhone\n");
    printf("------------------------------------------------\n");
    for(i=0; i<*n; i++) {
        j = ind[i].pos;
        printf("%d\t\t%s\t%s\t%s\n", mem[j].id, mem[j].name, mem[j].email, mem[j].phone);
    }
}
//FormAI DATASET v1.0 Category: Phone Book ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main() {
    printf("Oh Romeo, Romeo, wherefore art thou Romeo?\n");
    printf("I am here, my lady fair.\n");
    printf("What brings thee to this place, my love?\n");
    printf("To create a phone book, with contacts from above.\n");
    
    printf("Ah, I see. And how shall you go about this task?\n");
    printf("With code and logic, an algorithm to unmask.\n");
    printf("Pray tell, what is your plan?\n");
    printf("First, I shall create a struct for each contact, my dear man.\n");
    
    struct Contact {
        char name[50];
        char phone[20];
    };
    
    printf("And how many contacts do you plan to have?\n");
    printf("Let us say, a hundred or more.\n");
    printf("A hundred? That is quite a feat.\n");
    printf("Indeed, my love. But I shall not be beat.\n");
    
    int num_contacts;
    printf("How many contacts shall we create, my dear?\n");
    scanf("%d", &num_contacts);
    
    struct Contact contacts[num_contacts];
    int i;
    
    for (i = 0; i < num_contacts; i++) {
        printf("Enter contact name: ");
        scanf("%s", &contacts[i].name);
        
        printf("Enter contact phone number: ");
        scanf("%s", &contacts[i].phone);
    }
    
    printf("And how shall you display these contacts, my sweet?\n");
    printf("With a loop and printf, the perfect treat.\n");
    
    for (i = 0; i < num_contacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
    }
    
    printf("Truly, your skills with code doth impress me.\n");
    printf("Thank you, my love. Your words do bless me.\n");
    printf("Shall we save our phone book for future use?\n");
    printf("Indeed, we shall. To a file we must produce.\n");
    
    FILE *file = fopen("phone_book.txt", "w");
    for (i = 0; i < num_contacts; i++) {
        fprintf(file, "%s, %s\n", contacts[i].name, contacts[i].phone);
    }
    fclose(file);
    printf("Our phone book is safe, and we can rest.\n");
    
    return 0;
}
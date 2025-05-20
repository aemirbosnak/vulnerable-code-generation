//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mailing_list {
   char name[50];
   char address[100];
   char email[50];
};

int main() {
   int num_contacts;
   
   printf("O Romeo, Romeo! Wherefore art thou, Romeo?\n");
   printf("Enter the number of contacts in thy mailing list: ");
   scanf("%d", &num_contacts);

   struct mailing_list contacts[num_contacts];
   
   for(int i = 0; i < num_contacts; i++) {
      printf("What's in a name? That which we call a rose by any other name would smell as sweet.\n");
      printf("Enter thy Contact's name: ");
      scanf("%s", &contacts[i].name);
      
      printf("All the world's a stage, and all the men and women merely players:\n");
      printf("Enter thy Contact's address: ");
      scanf("%s", &contacts[i].address);
      
      printf("Good night, good night! parting is such sweet sorrow,\n");
      printf("That I shall say good night till it be morrow.\n");
      printf("Enter thy Contact's email: ");
      scanf("%s", &contacts[i].email);

      printf("\n");
   }
   
   printf("My bounty is as boundless as the sea, my love as deep; the more I give to thee,\n");
   printf("the more I have, for both are infinite.\n\n");

   printf("Printing your mailing list, O happy dagger!\n");

   for(int i = 0; i < num_contacts; i++) {
      printf("Contact %d:\n", i+1);
      printf("Name: %s\n", contacts[i].name);
      printf("Address: %s\n", contacts[i].address);
      printf("Email: %s\n", contacts[i].email);

      printf("\n");
   }
   
   printf("Parting is such sweet sorrow that I shall say good night till it be morrow.\n");

   return 0;
}
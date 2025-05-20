//FormAI DATASET v1.0 Category: Data mining ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

struct customer {
   int age;
   char gender[10];
   char location[20];
   float purchase_history[12];
};

int main() {
   struct customer c[100];
   int i, j;
   float avg_purchase, total_purchase = 0;
   
   // Gather data on customer purchases
   for(i = 0; i < 100; i++) {
      printf("\nEnter details for customer %d: \n", i+1);
      printf("Age: ");
      scanf("%d", &c[i].age);
      printf("Gender: ");
      scanf("%s", c[i].gender);
      printf("Location: ");
      scanf("%s", c[i].location);
      printf("Purchase history (for last 12 months): ");
      for(j = 0; j < 12; j++) {
         scanf("%f", &c[i].purchase_history[j]);
         total_purchase += c[i].purchase_history[j];
      }
   }

   avg_purchase = total_purchase / (i * 12);

   // Analyze data for patterns and trends
   printf("\n\nData Analysis: \n");
   printf("Average purchase amount: $%.2f\n", avg_purchase);
   printf("Purchase history by gender: \n");
   for(i = 0; i < 100; i++) {
      if(strcmp(c[i].gender, "male") == 0) {
         printf("Male customer %d: $%.2f\n", i+1, total_purchase/2);
      }
      else if(strcmp(c[i].gender, "female") == 0) {
         printf("Female customer %d: $%.2f\n", i+1, total_purchase/2);
      }
   }
   printf("Purchase history by age group: \n");
   for(i = 0; i < 100; i++) {
      if(c[i].age <= 25) {
         printf("Age group 18-25 customer %d: $%.2f\n", i+1, total_purchase/4);
      }
      else if(c[i].age > 25 && c[i].age <= 40) {
         printf("Age group 26-40 customer %d: $%.2f\n", i+1, total_purchase/4);
      }
      else if(c[i].age > 40 && c[i].age <= 60) {
         printf("Age group 41-60 customer %d: $%.2f\n", i+1, total_purchase/4);
      }
      else if(c[i].age > 60) {
         printf("Age group 61+ customer %d: $%.2f\n", i+1, total_purchase/4);
      }
   }
   
   return 0;
}
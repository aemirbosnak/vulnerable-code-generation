//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int num_of_customers = 0; // counter for number of customers

typedef struct {
   char name[20];
   int order_num;
   float amount;
} Order;

void *process_order(void *arg) {
   Order *new_order = (Order *)arg;
   printf("\nProcessing Order: %d", new_order->order_num);
   printf("\nCustomer Name: %s", new_order->name);
   printf("\nAmount: %.2f\n\n", new_order->amount);
   num_of_customers++;
   free(arg);
   pthread_exit(NULL);
}

int main() {
   int i, num_of_orders;
   printf("Enter number of orders: ");
   scanf("%d", &num_of_orders);
   Order *orders = (Order *)malloc(num_of_orders * sizeof(Order));
   pthread_t *threads = (pthread_t *)malloc(num_of_orders * sizeof(pthread_t));
   if (orders == NULL || threads == NULL) {
      printf("\nMemory allocation error, exiting...");
      exit(1);
   }
   for (i = 0; i < num_of_orders; i++) {
      printf("\nOrder %d:\n", i + 1);
      printf("Enter customer name: ");
      scanf("%s", orders[i].name);
      orders[i].order_num = i + 1;
      printf("Enter amount: ");
      scanf("%f", &orders[i].amount);
      pthread_create(&threads[i], NULL, process_order, &orders[i]);
   }
   for (i = 0; i < num_of_orders; i++) {
      pthread_join(threads[i], NULL);
   }
   printf("\nTotal number of orders processed: %d\n", num_of_orders);
   printf("Total number of customers: %d\n", num_of_customers);
   free(orders);
   free(threads);
   return 0;
}
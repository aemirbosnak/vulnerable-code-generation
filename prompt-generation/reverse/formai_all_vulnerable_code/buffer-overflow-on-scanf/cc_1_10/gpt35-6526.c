//FormAI DATASET v1.0 Category: Memory management ; Style: complete
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node* next;
};

struct node* head = NULL;

void insert(int x) {
   struct node* temp = (struct node*) malloc(sizeof(struct node));
   temp->data = x;
   temp->next = head;
   head = temp;
}

void print() {
   struct node* temp = head;
   printf("List: ");
   while(temp != NULL) {
      printf("%d ",temp->data);
      temp = temp->next;
   }
   printf("\n");
}

void delete(int n) {
   struct node* temp1 = head;
   if(n == 1) {
      head = temp1->next;
      free(temp1);
      return;
   }
   int i;
   for(i = 0;i < n-2;i++) {
      temp1 = temp1->next;
   }
   struct node* temp2 = temp1->next;
   temp1->next = temp2->next;
   free(temp2);
}

int main() {
   int n, i, x;
   printf("Enter the number of elements: ");
   scanf("%d",&n);
   for(i = 0;i < n;i++) {
      printf("Enter the element: ");
      scanf("%d",&x);
      insert(x);
      print();
   }
   printf("Enter the index of the element to be deleted: ");
   scanf("%d",&n);
   delete(n);
   print();
   return 0;
}
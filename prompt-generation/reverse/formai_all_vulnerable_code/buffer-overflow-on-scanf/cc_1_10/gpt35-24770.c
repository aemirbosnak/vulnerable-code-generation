//FormAI DATASET v1.0 Category: Database Indexing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Product {
  char name[20];
  int price;
  int quantity;
};

int binary_search(struct Product arr[], int l, int r, char key[]);
void insert(struct Product arr[], int* size, char name[], int price, int quantity);
void delete_product(struct Product arr[], int* size, char name[]);
void display(struct Product arr[], int size, char* criteria);
void merge_sort(struct Product arr[], int l, int r, char* criteria);
void merge(struct Product arr[], int l, int m, int r, char* criteria);

int main() {
  struct Product products[MAX];
  int size = 0;
  char input[20], input2[20];
  int price, quantity;
  int flag = -1;

  printf("Welcome to the Product Database!\n\n");

  while (1) {
    printf("Please choose an option:\n");
    printf("1. Add a product\n");
    printf("2. Delete a product\n");
    printf("3. Display all products\n");
    printf("4. Exit\n");

    scanf("%d", &flag);

    switch (flag) {
      case 1:
        printf("Please enter the name of the product: ");
        scanf("%s", input);

        printf("Please enter the price of the product: ");
        scanf("%d", &price);

        printf("Please enter the quantity of the product: ");
        scanf("%d", &quantity);

        insert(products, &size, input, price, quantity);
        printf("Product added.\n");
        break;
      
      case 2:
        printf("Please enter the name of the product: ");
        scanf("%s", input);

        delete_product(products, &size, input);
        break;

      case 3:
        printf("Please choose a sorting criteria (name/price/quantity): ");
        scanf("%s", input);

        display(products, size, input);
        break;

      default:
        printf("Thank you for using the Product Database!\n");
        exit(0);
    }
  }

  return 0;
}

// Binary Search to get index
int binary_search(struct Product arr[], int l, int r, char key[]) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
 
    if (strcmp(arr[mid].name, key) == 0) 
      return mid;
 
    if (strcmp(arr[mid].name, key) > 0) 
      return binary_search(arr, l, mid - 1, key);
 
    return binary_search(arr, mid + 1, r, key);
  }
 
  return -1;
}

// Insert Function to add product
void insert(struct Product arr[], int* size, char name[], int price, int quantity) {
  int i = binary_search(arr, 0, *size - 1, name);
 
  // If the product already exists in the database, update the values
  if (i != -1) {
    arr[i].price = price;
    arr[i].quantity = quantity;
    return;
  }
 
  // Otherwise, insert the product in alphabetical order
  int j = *size - 1;
  
  while (j >= 0 && strcmp(arr[j].name, name) > 0) {
    arr[j + 1] = arr[j];
    j--;
  }

  strcpy(arr[j + 1].name, name);
  arr[j + 1].price = price;
  arr[j + 1].quantity = quantity;
  (*size)++;
}

// Function to delete a product by name
void delete_product(struct Product arr[], int* size, char name[]) {
  int i = binary_search(arr, 0, *size - 1, name);
 
  // If the product doesn't exist in the database, do nothing
  if (i == -1) {
    printf("Product not found.\n");
    return;
  }
 
  // Otherwise, shift all products after it one index to the left
  for (int j = i; j < (*size) - 1; j++) {
    arr[j] = arr[j + 1];
  }
  (*size)--;
 
  printf("Product deleted.\n");
}

// Function to display all products in alphabetical order of its name
void display(struct Product arr[], int size, char* criteria) {
  merge_sort(arr, 0, size - 1, criteria);
 
  printf("%-20s %-10s %-10s\n", "Name", "Price", "Quantity");
  for (int i = 0; i < size; i++) {
    printf("%-20s %-10d %-10d\n", arr[i].name, arr[i].price, arr[i].quantity);
  }
}

// Recursion function for Merge Sort on the basis of name/price/quantity.
void merge_sort(struct Product arr[], int l, int r, char* criteria) {
  if (l >= r) return;
 
  int m = (l + r) / 2;
 
  merge_sort(arr, l, m, criteria);
  merge_sort(arr, m+1, r, criteria);
 
  merge(arr, l, m, r, criteria);
}

// Merging Function for Merge Sort 
void merge(struct Product arr[], int l, int m, int r, char* criteria) {
  struct Product left[m - l + 1], right[r - m];
 
  for (int i = 0; i < m - l + 1; i++)
    left[i] = arr[l + i];
 
  for (int i = 0; i < r - m; i++)
    right[i] = arr[m + 1 + i];
 
  int i = 0, j = 0, k = l;
 
  while (i < m - l + 1 && j < r - m) {
    int cmp;
 
      if (strcmp(criteria, "name") == 0) {
        cmp = strcmp(left[i].name, right[j].name);
      }
      else if (strcmp(criteria, "price") == 0) {
        cmp = left[i].price - right[j].price;
      }
      else if (strcmp(criteria, "quantity") == 0) {
        cmp = left[i].quantity - right[j].quantity;
      }
 
    if (cmp <= 0) {
      arr[k] = left[i];
      i++;
    }
    else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }
 
  while (i < m - l + 1) {
    arr[k] = left[i];
    i++;
    k++;
  }
 
  while (j < r - m) {
    arr[k] = right[j];
    j++;
    k++;
  }
}
//FormAI DATASET v1.0 Category: Database Indexing System ; Style: active
#include<stdio.h>
#include<string.h>

struct Student {
   int roll_number;
   char name[20];
   float cgpa;
}students[100];

void swap(struct Student *a, struct Student *b) {
   struct Student temp = *a;
   *a = *b;
   *b = temp;
}

int partition(struct Student arr[], int low, int high, int option) {
   if (option == 1) {
      int pivot = arr[high].roll_number;
      int i = (low - 1);

      for (int j = low; j <= high - 1; j++) {
         if (arr[j].roll_number <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
         }
      }
      swap(&arr[i + 1], &arr[high]);
      return (i + 1);
   }
   else if (option == 2) {
      char pivot[20];
      strcpy(pivot, arr[high].name);
      int i = (low - 1);

      for (int j = low; j <= high - 1; j++) {
         if (strcmp(arr[j].name, pivot) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
         }
      }
      swap(&arr[i + 1], &arr[high]);
      return (i + 1);
   }
   else if (option == 3) {
      float pivot = arr[high].cgpa;
      int i = (low - 1);

      for (int j = low; j <= high - 1; j++) {
         if (arr[j].cgpa >= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
         }
      }
      swap(&arr[i + 1], &arr[high]);
      return (i + 1);
   }
}

void quick_sort(struct Student arr[], int low, int high, int option) {
   if (low < high) {
      int pi = partition(arr, low, high, option);

      quick_sort(arr, low, pi - 1, option);
      quick_sort(arr, pi + 1, high, option);
   }
}

int binary_search_roll_number(struct Student arr[], int left, int right, int key) {
   while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid].roll_number == key)
         return mid;
      if (arr[mid].roll_number < key)
         left = mid + 1;
      else
         right = mid - 1;
   }
   return -1;
}

int binary_search_name(struct Student arr[], int left, int right, char *key) {
   while (left <= right) {
      int mid = left + (right - left) / 2;
      if (strcmp(arr[mid].name, key) == 0)
         return mid;
      if (strcmp(arr[mid].name, key) < 0)
         left = mid + 1;
      else
         right = mid - 1;
   }
   return -1;
}

// C Database Indexing System Example Program

int main() {
   int n;

   printf("Enter the number of students:\n");
   scanf("%d", &n);

   // Taking input
   for (int i = 0; i < n; i++) {
      printf("Enter roll number, name and CGPA of student %d:\n", i + 1);
      scanf("%d %s %f", &students[i].roll_number, students[i].name, &students[i].cgpa);
   }

   // Sorting based on Roll Number
   quick_sort(students, 0, n - 1, 1);

   // Searching based on Roll Number using Binary Search
   int key_1;
   printf("Enter roll number of student to search:\n");
   scanf("%d", &key_1);

   int index = binary_search_roll_number(students, 0, n - 1, key_1);

   if (index == -1) {
      printf("Student not found.\n");
   }
   else {
      printf("Student found at index %d:\nRoll Number: %d, Name: %s, CGPA: %.2f\n", index, students[index].roll_number, students[index].name, students[index].cgpa);
   }

   // Sorting based on Name
   quick_sort(students, 0, n - 1, 2);

   // Searching based on Name using Binary Search
   char key_2[20];
   printf("Enter name of student to search:\n");
   scanf("%s", key_2);

   index = binary_search_name(students, 0, n - 1, key_2);

   if (index == -1) {
      printf("Student not found.\n");
   }
   else {
      printf("Student found at index %d:\nRoll Number: %d, Name: %s, CGPA: %.2f\n", index, students[index].roll_number, students[index].name, students[index].cgpa);
   }

   // Sorting based on CGPA
   quick_sort(students, 0, n - 1, 3);

   // Printing based on CGPA
   printf("Students sorted based on CGPA:\n");
   for (int i = 0; i < n; i++) {
      printf("Roll Number: %d, Name: %s, CGPA: %.2f\n", students[i].roll_number, students[i].name, students[i].cgpa);
   }

   return 0;
}
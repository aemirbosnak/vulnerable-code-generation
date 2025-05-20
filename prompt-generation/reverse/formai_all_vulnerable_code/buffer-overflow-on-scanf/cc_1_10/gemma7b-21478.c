//Gemma-7B DATASET v1.0 Category: Database querying ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Record {
  char name[MAX_BUFFER_SIZE];
  int age;
  double salary;
} Record;

void query_database(Record *records, int num_records) {
  char query[MAX_BUFFER_SIZE];
  printf("Enter a query: ");
  scanf("%s", query);

  // Parse the query
  char *keywords = strtok(query, " ");
  int num_keywords = 0;
  while (keywords) {
    num_keywords++;
    keywords = strtok(NULL, " ");
  }

  // Filter the records
  int i = 0;
  for (i = 0; i < num_records; i++) {
    int flag = 1;
    for (int j = 0; j < num_keywords; j++) {
      if (strstr(records[i].name, keywords[j]) == NULL) {
        flag = 0;
      }
    }

    if (flag) {
      printf("Name: %s, Age: %d, Salary: %.2lf\n", records[i].name, records[i].age, records[i].salary);
    }
  }
}

int main() {
  Record records[] = {
    {"Donald Knuth", 75, 100000.0},
    {"Steve Jobs", 56, 900000.0},
    {"Bill Gates", 64, 800000.0},
    {"Warren Buffett", 88, 600000.0}
  };

  int num_records = 4;

  query_database(records, num_records);

  return 0;
}
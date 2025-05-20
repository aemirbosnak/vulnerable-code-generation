//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct { char name[21]; int value; } Element;

int compare(const void *a, const void *b) {
  const Element *elemA = (const Element *) a;
  const Element *elemB = (const Element *) b;

  return elemA->value - elemB->value;
}

void printElement(const Element *element) {
  int i;
  printf("%d - %s", element->value, element->name);

  for (i = 0; i < strlen(element->name) && isalpha(element->name[i]); i++)
    putchar(toupper(element->name[i]));

  putchar(' ');
}

int main() {
  int n;
  Element array[10];
  int i;

  printf("CLAUDE SHANNON SORTING EXAMPLE\n");

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%s%d", array[i].name, &array[i].value);
  }

  qsort(array, n, sizeof(Element), compare);

  puts("\nSorted array:");

  for (i = 0; i < n; i++) {
    printElement(&array[i]);
    if (i < n - 1)
      putchar(',');
    putchar('\n');
  }

  return 0;
}
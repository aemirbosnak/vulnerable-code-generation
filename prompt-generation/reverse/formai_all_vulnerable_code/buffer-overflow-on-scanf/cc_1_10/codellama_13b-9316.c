//Code Llama-13B DATASET v1.0 Category: Procedural Space Adventure ; Style: complex
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <ctype.h>
  #include <time.h>

  typedef struct {
    char name[20];
    int age;
    int height;
    int weight;
  } Person;

  void print_person(Person* p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Height: %d\n", p->height);
    printf("Weight: %d\n", p->weight);
  }

  int main() {
    srand(time(NULL));

    Person p1;
    strcpy(p1.name, "John Doe");
    p1.age = 30;
    p1.height = 175;
    p1.weight = 70;

    Person p2;
    strcpy(p2.name, "Jane Doe");
    p2.age = 25;
    p2.height = 160;
    p2.weight = 55;

    Person p3;
    strcpy(p3.name, "Bob Smith");
    p3.age = 40;
    p3.height = 185;
    p3.weight = 80;

    int choice;
    while (1) {
      printf("1. Print Person 1\n");
      printf("2. Print Person 2\n");
      printf("3. Print Person 3\n");
      printf("4. Quit\n");
      scanf("%d", &choice);
      switch (choice) {
        case 1:
          print_person(&p1);
          break;
        case 2:
          print_person(&p2);
          break;
        case 3:
          print_person(&p3);
          break;
        case 4:
          return 0;
          break;
        default:
          printf("Invalid choice\n");
          break;
      }
    }
    return 0;
  }
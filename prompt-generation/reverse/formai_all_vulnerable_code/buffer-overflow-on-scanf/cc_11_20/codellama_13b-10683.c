//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: retro
// Medical Store Management System Example Program in a Retro Style
  #include <stdio.h>
  #include <string.h>

  struct patient {
    char name[50];
    char address[50];
    char contact[20];
    char disease[50];
  };

  int main() {
    struct patient patients[50];
    int i, n = 0;
    char choice, c;

    do {
      printf("Welcome to the Medical Store Management System!\n");
      printf("1. Add new patient\n");
      printf("2. View patients\n");
      printf("3. Search patient\n");
      printf("4. Update patient information\n");
      printf("5. Delete patient\n");
      printf("6. Exit\n");
      printf("Enter your choice: ");
      scanf("%c", &choice);

      switch (choice) {
      case '1':
        printf("Add new patient\n");
        printf("Enter patient name: ");
        scanf("%s", patients[n].name);
        printf("Enter patient address: ");
        scanf("%s", patients[n].address);
        printf("Enter patient contact: ");
        scanf("%s", patients[n].contact);
        printf("Enter patient disease: ");
        scanf("%s", patients[n].disease);
        n++;
        break;
      case '2':
        printf("View patients\n");
        for (i = 0; i < n; i++) {
          printf("%d. %s\n", i + 1, patients[i].name);
        }
        break;
      case '3':
        printf("Search patient\n");
        printf("Enter patient name: ");
        scanf("%s", c);
        for (i = 0; i < n; i++) {
          if (strcmp(patients[i].name, c) == 0) {
            printf("Patient found!\n");
            printf("Name: %s\n", patients[i].name);
            printf("Address: %s\n", patients[i].address);
            printf("Contact: %s\n", patients[i].contact);
            printf("Disease: %s\n", patients[i].disease);
          }
        }
        break;
      case '4':
        printf("Update patient information\n");
        printf("Enter patient name: ");
        scanf("%s", c);
        for (i = 0; i < n; i++) {
          if (strcmp(patients[i].name, c) == 0) {
            printf("Enter patient address: ");
            scanf("%s", patients[i].address);
            printf("Enter patient contact: ");
            scanf("%s", patients[i].contact);
            printf("Enter patient disease: ");
            scanf("%s", patients[i].disease);
          }
        }
        break;
      case '5':
        printf("Delete patient\n");
        printf("Enter patient name: ");
        scanf("%s", c);
        for (i = 0; i < n; i++) {
          if (strcmp(patients[i].name, c) == 0) {
            for (int j = i; j < n - 1; j++) {
              patients[j] = patients[j + 1];
            }
            n--;
            break;
          }
        }
        break;
      case '6':
        printf("Exit\n");
        break;
      default:
        printf("Invalid choice!\n");
      }
    } while (choice != '6');

    return 0;
  }
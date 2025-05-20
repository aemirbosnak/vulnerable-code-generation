//Code Llama-13B DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  struct Password {
    char name[20];
    char password[20];
  };

  void get_password(struct Password* pwd) {
    printf("Enter the name of the password: ");
    scanf("%s", pwd->name);
    printf("Enter the password: ");
    scanf("%s", pwd->password);
  }

  void save_password(struct Password* pwd) {
    FILE* file = fopen("passwords.txt", "a");
    if (file == NULL) {
      printf("Error opening file");
      return;
    }
    fprintf(file, "%s:%s\n", pwd->name, pwd->password);
    fclose(file);
  }

  void retrieve_password(char* name) {
    FILE* file = fopen("passwords.txt", "r");
    if (file == NULL) {
      printf("Error opening file");
      return;
    }
    char line[100];
    while (fgets(line, 100, file)) {
      if (strstr(line, name) != NULL) {
        printf("Password: %s\n", line + strlen(name) + 1);
        break;
      }
    }
    fclose(file);
  }

  void delete_password(char* name) {
    FILE* file = fopen("passwords.txt", "r");
    if (file == NULL) {
      printf("Error opening file");
      return;
    }
    char line[100];
    FILE* tmp = fopen("tmp.txt", "w");
    while (fgets(line, 100, file)) {
      if (strstr(line, name) == NULL) {
        fprintf(tmp, "%s", line);
      }
    }
    fclose(file);
    fclose(tmp);
    remove("passwords.txt");
    rename("tmp.txt", "passwords.txt");
  }

  int main() {
    struct Password pwd;
    int choice;
    while (1) {
      printf("1. Get password\n2. Save password\n3. Retrieve password\n4. Delete password\n5. Exit\n");
      scanf("%d", &choice);
      switch (choice) {
      case 1:
        get_password(&pwd);
        break;
      case 2:
        save_password(&pwd);
        break;
      case 3:
        retrieve_password(pwd.name);
        break;
      case 4:
        delete_password(pwd.name);
        break;
      case 5:
        exit(0);
        break;
      default:
        printf("Invalid choice\n");
        break;
      }
    }
    return 0;
  }
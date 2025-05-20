//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: surprised
int main() {
  char name[20];
  char email[20];
  char password[20];
  char choice;
  int i;

  // Prompt user for name and email
  printf("Enter your name: ");
  scanf("%s", name);
  printf("Enter your email: ");
  scanf("%s", email);
  printf("Enter your password: ");
  scanf("%s", password);

  // Create a new mailing list
  char mailing_list[100][100];

  // Add user to mailing list
  strcpy(mailing_list[0], name);
  strcpy(mailing_list[1], email);
  strcpy(mailing_list[2], password);

  // Loop to add more users to mailing list
  for (i = 3; i < 100; i++) {
    printf("Add another user? (y/n): ");
    scanf("%c", &choice);
    if (choice == 'n') {
      break;
    }
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter email: ");
    scanf("%s", email);
    printf("Enter password: ");
    scanf("%s", password);
    strcpy(mailing_list[i], name);
    strcpy(mailing_list[i + 1], email);
    strcpy(mailing_list[i + 2], password);
  }

  // Display mailing list
  for (i = 0; i < 100; i += 3) {
    printf("Name: %s\n", mailing_list[i]);
    printf("Email: %s\n", mailing_list[i + 1]);
    printf("Password: %s\n", mailing_list[i + 2]);
    printf("\n");
  }

  return 0;
}
//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: peaceful
#include <stdio.h>
  #include <string.h>
  #include <ctype.h>

  #define MIN_PASSWORD_LENGTH 8
  #define MAX_PASSWORD_LENGTH 128

  typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
    int uppercase;
    int lowercase;
    int digits;
    int special;
  } password_t;

  void check_password_length(password_t* password) {
    if (password->length < MIN_PASSWORD_LENGTH) {
      printf("Password too short. Must be at least %d characters long.\n", MIN_PASSWORD_LENGTH);
      return;
    }

    if (password->length > MAX_PASSWORD_LENGTH) {
      printf("Password too long. Must be at most %d characters long.\n", MAX_PASSWORD_LENGTH);
      return;
    }
  }

  void check_password_characters(password_t* password) {
    int i;

    for (i = 0; i < password->length; i++) {
      if (isupper(password->password[i])) {
        password->uppercase++;
      } else if (islower(password->password[i])) {
        password->lowercase++;
      } else if (isdigit(password->password[i])) {
        password->digits++;
      } else if (ispunct(password->password[i])) {
        password->special++;
      }
    }
  }

  void check_password_complexity(password_t* password) {
    if (password->uppercase == 0) {
      printf("Password must contain at least one uppercase letter.\n");
    }

    if (password->lowercase == 0) {
      printf("Password must contain at least one lowercase letter.\n");
    }

    if (password->digits == 0) {
      printf("Password must contain at least one digit.\n");
    }

    if (password->special == 0) {
      printf("Password must contain at least one special character.\n");
    }
  }

  void print_password_status(password_t* password) {
    printf("Password: %s\n", password->password);
    printf("Length: %d\n", password->length);
    printf("Uppercase: %d\n", password->uppercase);
    printf("Lowercase: %d\n", password->lowercase);
    printf("Digits: %d\n", password->digits);
    printf("Special: %d\n", password->special);
  }

  int main() {
    password_t password;

    printf("Enter password: ");
    fgets(password.password, MAX_PASSWORD_LENGTH, stdin);
    password.length = strlen(password.password);

    check_password_length(&password);
    check_password_characters(&password);
    check_password_complexity(&password);

    print_password_status(&password);

    return 0;
  }
//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: Cryptic
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

struct password {
  char *pw;
  int len;
  int strength;
};

int main() {
  // seed random number generator
  srand(time(NULL));

  // get password from user
  char pw[100];
  printf("Enter a password: ");
  scanf("%s", pw);

  // create password struct
  struct password pw_info;
  pw_info.pw = pw;
  pw_info.len = strlen(pw);

  // calculate password strength

  // check password length
  if (pw_info.len < 8) {
    pw_info.strength = 0;
  } else if (pw_info.len >= 8 && pw_info.len <= 12) {
    pw_info.strength = 1;
  } else if (pw_info.len > 12 && pw_info.len <= 16) {
    pw_info.strength = 2;
  } else {
    pw_info.strength = 3;
  }

  // check password for uppercase letters
  int has_uppercase = 0;
  for (int i = 0; i < pw_info.len; i++) {
    if (isupper(pw_info.pw[i])) {
      has_uppercase = 1;
      break;
    }
  }

  if (has_uppercase) {
    pw_info.strength++;
  }

  // check password for lowercase letters
  int has_lowercase = 0;
  for (int i = 0; i < pw_info.len; i++) {
    if (islower(pw_info.pw[i])) {
      has_lowercase = 1;
      break;
    }
  }

  if (has_lowercase) {
    pw_info.strength++;
  }

  // check password for numbers
  int has_numbers = 0;
  for (int i = 0; i < pw_info.len; i++) {
    if (isdigit(pw_info.pw[i])) {
      has_numbers = 1;
      break;
    }
  }

  if (has_numbers) {
    pw_info.strength++;
  }

  // check password for special characters
  int has_special_chars = 0;
  for (int i = 0; i < pw_info.len; i++) {
    if (!isalnum(pw_info.pw[i]) && !isspace(pw_info.pw[i])) {
      has_special_chars = 1;
      break;
    }
  }

  if (has_special_chars) {
    pw_info.strength++;
  }

  // calculate entropy of password
  double entropy = 0;
  for (int i = 0; i < pw_info.len; i++) {
    entropy += log2(256);
  }

  pw_info.strength += (int)(entropy / 10);

  // print password strength
  printf("Password strength: %d\n", pw_info.strength);

  return 0;
}
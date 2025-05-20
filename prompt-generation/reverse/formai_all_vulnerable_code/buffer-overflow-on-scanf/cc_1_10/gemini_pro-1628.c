//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Let's call a spade a spade, weak passwords suck!
#define WEAK_PASSWORD_THRESHOLD 6

// Password too weak? Too bad, we'll mock you mercilessly!
void mock_weak_password(char *password) {
  printf("Oh, honey, that password is weaker than a baby's sneeze!\n");
  printf("You might as well put up a sign that says, \"Please hack me, I'm an easy target!\"\n");
  printf("Seriously, go back to kindergarten and learn some basic password hygiene.\n\n");
}

// Password is strong enough? We'll give you a standing ovation!
void praise_strong_password(char *password) {
  printf("Wowzers, that password is stronger than a titanium vault!\n");
  printf("You're like a cybersecurity ninja, keeping those hackers at bay.\n");
  printf("Keep up the good work, password master!\n\n");
}

// The main event: let's see if your password has the guts to pass our test!
int main() {
  char password[100]; // Let's give you plenty of room to express your password prowess

  // Get ready to type your password, but don't peek at the screen!
  printf("Enter your password, but remember, don't be a wimp about it!\n");
  scanf("%s", password);

  // Let's calculate the strength of that password, shall we?
  int password_strength = 0;
  int password_length = strlen(password);

  // Check for password length: if it's too short, you're in trouble!
  if (password_length < 8) {
    printf("Seriously? Your password is shorter than a goldfish's attention span!\n");
    password_strength += 1; // Adding a penalty point for being too short
  }

  // Check for uppercase letters: the more, the merrier!
  int uppercase_count = 0;
  for (int i = 0; i < password_length; i++) {
    if (password[i] >= 'A' && password[i] <= 'Z') {
      uppercase_count++;
    }
  }
  if (uppercase_count == 0) {
    printf("Where are the uppercase letters? Your password is as flat as a pancake!\n");
    password_strength += 1; // Another penalty point for no uppercase
  }

  // Check for lowercase letters: a mix of cases is a good sign!
  int lowercase_count = 0;
  for (int i = 0; i < password_length; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      lowercase_count++;
    }
  }
  if (lowercase_count == 0) {
    printf("All uppercase? Your password is like a screaming toddler, all noise and no substance!\n");
    password_strength += 1; // And another penalty point for no lowercase
  }

  // Check for numbers: they add some extra muscle to your password!
  int number_count = 0;
  for (int i = 0; i < password_length; i++) {
    if (password[i] >= '0' && password[i] <= '9') {
      number_count++;
    }
  }
  if (number_count == 0) {
    printf("No numbers? Your password is like a math test with no answers!\n");
    password_strength += 1; // You guessed it, another penalty point for no numbers
  }

  // Check for special characters: they're the secret sauce of strong passwords!
  int special_char_count = 0;
  for (int i = 0; i < password_length; i++) {
    if ((password[i] >= '!' && password[i] <= '/') || (password[i] >= ':' && password[i] <= '@') || (password[i] >= '[' && password[i] <= '`')) {
      special_char_count++;
    }
  }
  if (special_char_count == 0) {
    printf("No special characters? Your password is as bland as oatmeal without sugar!\n");
    password_strength += 1; // And finally, a penalty point for no special characters
  }

  // Now, let's face the music and see how strong your password really is!
  if (password_strength >= WEAK_PASSWORD_THRESHOLD) {
    mock_weak_password(password);
  } else {
    praise_strong_password(password);
  }

  return 0; // Mission accomplished, we've rated your password and had a few laughs along the way!
}
//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: Romeo and Juliet
// Love's labor's lost, in password's might,
// A test of strength, in Juliet's plight.

#include <stdio.h>
#include <string.h>

// Romeo's passion, a heart aflame,
// A strength test algorithm in his name.

int Romeo(char *word) {
  // Words that vie with thoughts unspoken,
  // Length too short, passion broken.

  if (strlen(word) < 8) {
    return 0;
  }

  // A score to measure, strength unfurled,
  // Each character, a precious pearl.

  int score = 0;

  // Letters, numbers, and symbols blended,
  // A tapestry of strength, defended.

  for (int i = 0; i < strlen(word); i++) {
    char c = word[i];
    if (c >= 'A' && c <= 'Z') {
      score += 2;
    } else if (c >= 'a' && c <= 'z') {
      score += 1;
    } else if (c >= '0' && c <= '9') {
      score += 3;
    } else {
      score += 4;
    }
  }

  // Repeating characters, a flaw to mend,
  // Strength diminished, passion at an end.

  for (int i = 0; i < strlen(word) - 1; i++) {
    if (word[i] == word[i + 1]) {
      score -= 1;
    }
  }

  // A score of passion, strong and true,
  // A password of strength, Romeo's due.

  return score;
}

// Juliet's wisdom, serene and wise,
// A strength test algorithm of her guise.

int Juliet(char *word) {
  // Strength in numbers, her guiding light,
  // Longest words, her beacon bright.

  int longest = 0;
  for (int i = 0; i < strlen(word); i++) {
    if (word[i] != ' ') {
      longest++;
    } else {
      longest = 0;
    }
  }

  // Vowels and consonants, hand in glove,
  // A balance of strength, fit for her love.

  int vowels = 0;
  for (int i = 0; i < strlen(word); i++) {
    char c = word[i];
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      vowels++;
    } else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
      vowels++;
    }
  }
  int consonants = strlen(word) - vowels;

  // Special characters, a secret guise,
  // Strength in obscurity, her love's surprise.

  int specials = 0;
  for (int i = 0; i < strlen(word); i++) {
    char c = word[i];
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
      continue;
    } else {
      specials++;
    }
  }

  // A score of cunning, sharp and keen,
  // A password of strength, Juliet's queen.

  return longest * vowels * consonants * specials;
}

// Their love, a symphony divine,
// Two algorithms, entwined and fine.

int main() {
  // A tale of strength, a love's decree,
  // A password's might, for all to see.

  char word[101];
  printf("Enter a password, my love so true:\n");
  scanf("%s", word);

  // Romeo's might and Juliet's art,
  // United in strength, a love apart.

  int romeoScore = Romeo(word);
  int julietScore = Juliet(word);
  int strengthScore = romeoScore + julietScore;

  // A strength revealed, a love proclaimed,
  // A password's might, forever named.

  printf("Your password's strength, a tale to unfold:\n");
  if (strengthScore < 10) {
    printf("Weak as water, love's fire unfulfilled.\n");
  } else if (strengthScore < 20) {
    printf("Fairly strong, yet love's potential revealed.\n");
  } else if (strengthScore < 30) {
    printf("Strong as steel, love's flame concealed.\n");
  } else {
    printf("Unbreakable, love's eternal decree.\n");
  }

  // A love that's strong, a password's might,
  // A tale of Juliet and Romeo's plight.

  return 0;
}
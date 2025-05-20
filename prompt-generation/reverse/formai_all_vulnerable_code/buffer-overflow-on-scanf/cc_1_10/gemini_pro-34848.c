//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A warm and fuzzy function to compare two strings
int compare_strings(char *str1, char *str2) {
  int i, len1, len2;
  len1 = strlen(str1);
  len2 = strlen(str2);
  if (len1 != len2) {
    return 0;
  }
  for (i = 0; i < len1; i++) {
    if (str1[i] != str2[i]) {
      return 0;
    }
  }
  return 1;
}

// A valiant knight to scan for viruses
int scan_for_viruses(char *filename) {
  char *virus_signatures[] = {"I love you", "ILOVEYOU", "Melissa", "Anna Kournikova"};
  int i, num_signatures = sizeof(virus_signatures) / sizeof(char *);
  FILE *fp;
  char buffer[1024];
  if ((fp = fopen(filename, "r")) == NULL) {
    printf("Oh no, I can't open your file, fair maiden!\n");
    return 1;
  }
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    for (i = 0; i < num_signatures; i++) {
      if (compare_strings(buffer, virus_signatures[i])) {
        printf("Alas, I've found a virus in your file, my precious!\n");
        fclose(fp);
        return 1;
      }
    }
  }
  fclose(fp);
  printf("Fear not, my love! Your file is free from viruses.\n");
  return 0;
}

// The main event, where love and security intertwine
int main() {
  char filename[100];
  printf("My dearest, what is the path to your file that needs my protection?\n");
  scanf("%s", filename);
  if (scan_for_viruses(filename) == 0) {
    printf("My love, your file is now safe from the evil viruses.\n");
  }
  return 0;
}
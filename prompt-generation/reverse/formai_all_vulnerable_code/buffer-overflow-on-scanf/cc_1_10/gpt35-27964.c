//FormAI DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <string.h>

int main() {
  char str1[50], str2[50], str3[50];
  printf("Enter string 1: ");
  scanf("%s", str1);
  printf("Enter string 2: ");
  scanf("%s", str2);

  int len1 = strlen(str1);
  int len2 = strlen(str2);

  if (len1 > len2) {
    printf("String 1 is longer than string 2\n");

    // Concatenate string 2 with itself
    for (int i=0; i<len2; i++) {
      str3[i] = str2[i];
      str3[i+len2] = str2[i];
    }
    str3[len1] = '\0'; 

    printf("The resulting string is %s\n", str3);
  } else if (len1 < len2) {
    printf("String 2 is longer than string 1\n");

    // Reverse string 1 and append to string 2
    for (int i=0; i<len1; i++) {
      str3[i] = str1[len1-i-1];
    }
    for (int i=len1; i<len1+len2; i++) {
      str3[i] = str2[i-len1];
    }
    str3[len1+len2] = '\0';

    printf("The resulting string is %s\n", str3);
  } else {
    printf("String 1 and string 2 are the same length\n");

    // Rotate the characters in each string by 1 position
    for (int i=0; i<len1; i++) {
      str3[i] = (str1[i]+1)%256;
    }
    str3[len1] = ' ';
    for (int i=0; i<len2; i++) {
      str3[len1+i+1] = (str2[i]+1)%256;
    }
    str3[len1+len2+1] = '\0';

    printf("The resulting string is %s\n", str3);
  }

  return 0;
}
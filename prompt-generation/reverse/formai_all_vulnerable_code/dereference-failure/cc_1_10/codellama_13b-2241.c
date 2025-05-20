//Code Llama-13B DATASET v1.0 Category: Natural Language Date Converter ; Style: Cryptic
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int main(int argc, char *argv[]) {
      char *input = argv[1];
      int len = strlen(input);

      if (len < 10) {
        printf("Invalid input length\n");
        return 1;
      }

      char month[3];
      char day[3];
      char year[5];

      int i = 0;
      int j = 0;
      while (i < len) {
        if (input[i] == '/') {
          i++;
          continue;
        }
        if (j < 3) {
          month[j] = input[i];
          j++;
        } else if (j == 3) {
          month[j] = '\0';
          j++;
        } else if (j < 6) {
          day[j - 4] = input[i];
          j++;
        } else if (j == 6) {
          day[j - 4] = '\0';
          j++;
        } else {
          year[j - 7] = input[i];
          j++;
        }
        i++;
      }
      year[4] = '\0';

      printf("Month: %s\n", month);
      printf("Day: %s\n", day);
      printf("Year: %s\n", year);

      return 0;
    }
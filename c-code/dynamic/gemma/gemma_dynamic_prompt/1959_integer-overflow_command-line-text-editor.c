#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buf[1];
  int x = 0;
  while (1) {
    printf("Enter command: ");
    scanf("%s", buf);

    switch (buf[0]) {
      case 'a':
        printf("Enter text: ");
        scanf("%s", buf);
        x = atoi(buf);
        printf("Value: %d\n", x);
        break;
      case 'e':
        exit(0);
    }
  }
}

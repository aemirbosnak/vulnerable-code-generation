#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main()
{
  int image[10][10] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                            {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
                            // ... continued for the remaining 8 rows ...
  };

  // Accessing an element beyond the bounds of the array
  int pixel = image[10][10]; // This will lead to undefined behavior

  // The remaining code ...
}

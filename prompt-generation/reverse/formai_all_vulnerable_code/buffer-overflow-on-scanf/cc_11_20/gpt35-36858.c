//FormAI DATASET v1.0 Category: Pattern printing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int rows, cols, gap, row, col, num, count, flag, direction;
  char pattern[4][4] = {{'C', 'H', 'A', 'T'},
                        {'B', 'O', 'T', 'S'},
                        {'R', 'O', 'C', 'K'},
                        {'S', 'T', 'A', 'R'}};

  printf("\nEnter the number of rows and columns of the pattern: ");
  scanf("%d%d", &rows, &cols);
  
  if(rows < 4 || cols < 4)
  {
    printf("\nPattern size should be atleast 4 x 4.");
    exit(0);
  }
  
  gap = rows - 2;
  num = 1;
  count = 0;
  flag = 0;
  direction = 1;
  
  for(row = 0; row < rows; row++)
  {
    for(col = 0; col < cols; col++)
    {
      if(row == 0 || row == rows - 1 || col == 0 || col == cols - 1)
      {
        putchar('*');
      }
      else
      {
        putchar(pattern[row - 1][col - 1]);
      }
    }
    
    putchar('\n');
    
    if(row == 0 || row == rows - 1)
    {
      continue;
    }
    
    count++;
    
    if(count == gap || flag == 1)
    {
      direction *= -1;
      count = 0;
      flag = 0;
    }
    
    num += direction;
    
    for(col = 0; col < cols; col++)
    {
      if(col == 0 || col == cols - 1)
      {
        putchar('*');
      }
      else if(col == num)
      {
        putchar(pattern[row - 1][col - 1]);
        flag = 1;
      }
      else
      {
        putchar(' ');
      }
    }
    
    putchar('\n');
  }
  return 0;
}
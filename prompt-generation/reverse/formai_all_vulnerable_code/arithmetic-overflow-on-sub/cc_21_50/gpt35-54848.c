//FormAI DATASET v1.0 Category: Image Editor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char original[50], output[50];
  int choice;
  FILE *in_file, *out_file;

  printf("Enter the name of the original image file: ");
  scanf("%s", original);

  printf("Enter the name of the output image file: ");
  scanf("%s", output);

  printf("What operation would you like to perform on the image?\n");
  printf("1. Rotate\n");
  printf("2. Grayscale\n");
  printf("3. Invert\n");
  printf("4. Brighten\n");
  printf("5. Darken\n");
  printf("6. Blur\n");
  printf("7. Sharpen\n");

  printf("Enter your choice (1-7): ");
  scanf("%d", &choice);

  in_file = fopen(original, "rb");
  out_file = fopen(output, "wb");

  if (in_file == NULL || out_file == NULL)
  {
    printf("Error opening files!\n");
    exit(1);
  }

  int width, height, maxval;
  char magic[3];

  fscanf(in_file, "%s", magic);
  fscanf(in_file, "%d %d", &width, &height);
  fscanf(in_file, "%d", &maxval);

  int i, j, index;
  unsigned char pixel[3];
  unsigned char buffer[width * height * 3];

  for (i = 0; i < width * height * 3; i += 3)
  {
    fread(pixel, sizeof(unsigned char), 3, in_file);
    buffer[i] = pixel[0];
    buffer[i + 1] = pixel[1];
    buffer[i + 2] = pixel[2];
  }

  switch (choice)
  {
  case 1:
    for (i = 0; i < height; i++)
    {
      for (j = 0; j < width; j++)
      {
        index = (i * width + j) * 3;
        unsigned char temp = buffer[index];
        buffer[index] = buffer[index + 2];
        buffer[index + 2] = temp;
      }
    }
    break;

  case 2:
    for (i = 0; i < width * height * 3; i += 3)
    {
      unsigned char gray = (buffer[i] + buffer[i + 1] + buffer[i + 2]) / 3;
      buffer[i] = buffer[i + 1] = buffer[i + 2] = gray;
    }
    break;

  case 3:
    for (i = 0; i < width * height * 3; i++)
    {
      buffer[i] = maxval - buffer[i];
    }
    break;

  case 4:
    for (i = 0; i < width * height * 3; i++)
    {
      buffer[i] += 50;
    }
    break;

  case 5:
    for (i = 0; i < width * height * 3; i++)
    {
      buffer[i] -= 50;
    }
    break;

  case 6:
    for (i = 1; i < height - 1; i++)
    {
      for (j = 1; j < width - 1; j++)
      {
        index = (i * width + j) * 3;
        int k, l, count = 0;
        int sum_r = 0, sum_g = 0, sum_b = 0;
        for (k = -1; k <= 1; k++)
        {
          for (l = -1; l <= 1; l++)
          {
            int idx = ((i + k) * width + (j + l)) * 3;
            sum_r += buffer[idx];
            sum_g += buffer[idx + 1];
            sum_b += buffer[idx + 2];
            count++;
          }
        }
        buffer[index] = sum_r / count;
        buffer[index + 1] = sum_g / count;
        buffer[index + 2] = sum_b / count;
      }
    }
    break;

  case 7:
    for (i = 1; i < height - 1; i++)
    {
      for (j = 1; j < width - 1; j++)
      {
        index = (i * width + j) * 3;
        int k, l;
        int sum_r = 0, sum_g = 0, sum_b = 0;
        for (k = -1; k <= 1; k++)
        {
          for (l = -1; l <= 1; l++)
          {
            int idx = ((i + k) * width + (j + l)) * 3;
            if (k == 0 && l == 0)
            {
              sum_r += 9 * buffer[idx];
              sum_g += 9 * buffer[idx + 1];
              sum_b += 9 * buffer[idx + 2];
            }
            else
            {
              sum_r -= buffer[idx];
              sum_g -= buffer[idx + 1];
              sum_b -= buffer[idx + 2];
            }
          }
        }
        buffer[index] = sum_r / 16;
        buffer[index + 1] = sum_g / 16;
        buffer[index + 2] = sum_b / 16;
      }
    }
    break;

  default:
    printf("Invalid choice!\n");
    exit(1);
  }

  fprintf(out_file, "%s\n", magic);
  fprintf(out_file, "%d %d\n", width, height);
  fprintf(out_file, "%d\n", maxval);

  for (i = 0; i < width * height * 3; i += 3)
  {
    pixel[0] = buffer[i];
    pixel[1] = buffer[i + 1];
    pixel[2] = buffer[i + 2];
    fwrite(pixel, sizeof(unsigned char), 3, out_file);
  }

  fclose(in_file);
  fclose(out_file);

  printf("The %s file has been edited and saved in %s file.\n", original, output);

  return 0;
}
//FormAI DATASET v1.0 Category: Color Code Converter ; Style: inquisitive
#include<stdio.h>
#include<string.h>

int main()
{
	char hex[7];
	int len, dec = 0, i, j;
	char rgb[11];
	
	printf("Enter a 6 digit hex value (without #): ");
	scanf("%s", hex);
	
	len = strlen(hex);
	
	if(len != 6)
	{
		printf("Error: Invalid hex value\n");
		return 0;
	}
	
	for(i = 0, j = len-1; i < len; i++, j--)
	{
		if(hex[i] >= 48 && hex[i] <= 57)
		{
			dec += (hex[i] - 48) * pow(16, j);
		}
		else if(hex[i] >= 65 && hex[i] <= 70)
		{
			dec += (hex[i] - 55) * pow(16, j);
		}
		else if(hex[i] >= 97 && hex[i] <= 102)
		{
			dec += (hex[i] - 87) * pow(16, j);
		}
		else
		{
			printf("Error: Invalid hex value\n");
			return 0;
		}
	}
	
	int red = (dec & 0xFF0000) >> 16;
	int green = (dec & 0x00FF00) >> 8;
	int blue = dec & 0x0000FF;
	
	sprintf(rgb, "RGB (%d, %d, %d)", red, green, blue);
	
	printf("%s\n", rgb);
	
	return 0;
}
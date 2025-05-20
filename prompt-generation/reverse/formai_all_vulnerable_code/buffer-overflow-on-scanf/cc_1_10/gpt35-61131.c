//FormAI DATASET v1.0 Category: Database querying ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <stdbool.h>

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}

int main(int argc, char **argv)
{
  MYSQL *con = mysql_init(NULL);
  
  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }  

  if (mysql_real_connect(con, "localhost", "user", "password", "database", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);
  }    

  bool is_valid_input = false;
  char input[20];
  do {
    printf("Enter student ID: ");
    scanf("%s",input);
    for (int i=0; input[i] != '\0'; i++){
      if (!isdigit(input[i])){
        printf("Invalid input. Please enter a numeric ID.\n");
        is_valid_input = false;
        break;
      }
      else {
        is_valid_input = true;
      }
    }
  } while (!is_valid_input);

  char query[200];
  sprintf(query, "SELECT * FROM students WHERE student_id = %s", input);

  if (mysql_query(con, query)) 
  {
      finish_with_error(con);
  }

  MYSQL_RES *result = mysql_store_result(con);

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;
  if ((row = mysql_fetch_row(result))) 
  { 
      for(int i = 0; i < num_fields; i++) 
      { 
          printf("%s ", row[i] ? row[i] : "NULL"); 
      } 
      printf("\n"); 
  } 

  mysql_free_result(result);
  mysql_close(con);

  return 0;
}
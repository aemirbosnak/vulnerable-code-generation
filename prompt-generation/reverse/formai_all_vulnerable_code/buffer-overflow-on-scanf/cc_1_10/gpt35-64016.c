//FormAI DATASET v1.0 Category: Database querying ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h> // Include MySQL library

#define SERVER "localhost"
#define USER "root"
#define PASSWORD "password"
#define DATABASE "exampledb"

MYSQL *conn; // Define MySQL connection

void display_menu();

void connect_to_database()
{
   conn = mysql_init(NULL);

   if (!mysql_real_connect(conn, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0))
   {
      printf("Error connecting to database: %s\n", mysql_error(conn));
      exit(1);
   }

   printf("Connected to database successfully!\n");
}

void query_all_data()
{
   if (mysql_query(conn, "SELECT * FROM users"))
   {
      printf("Error executing query: %s\n", mysql_error(conn));
      exit(1);
   }

   MYSQL_RES *result = mysql_store_result(conn);

   int num_fields = mysql_num_fields(result);

   MYSQL_ROW row;

   while ((row = mysql_fetch_row(result)))
   {
      for (int i = 0; i < num_fields; i++)
      {
         printf("%-20s ", row[i] ? row[i] : "NULL");
      }
      printf("\n");
   }

   mysql_free_result(result); // Free memory used for result
}

void query_data_by_id()
{
   char id[10];

   printf("Enter the ID to retrieve data: ");
   scanf("%s", id);

   char query[100];

   sprintf(query, "SELECT * FROM users WHERE id = %s", id);

   if (mysql_query(conn, query))
   {
      printf("Error executing query: %s\n", mysql_error(conn));
      exit(1);
   }

   MYSQL_RES *result = mysql_store_result(conn);

   MYSQL_ROW row;

   if ((row = mysql_fetch_row(result)))
   {
      printf("ID: %s\n", row[0] ? row[0] : "NULL");
      printf("Name: %s\n", row[1] ? row[1] : "NULL");
      printf("Email: %s\n", row[2] ? row[2] : "NULL");
   }
   else
   {
      printf("No data found with specified ID!\n");
   }

   mysql_free_result(result); // Free memory used for result
}

void add_data()
{
   char name[50];
   char email[50];

   printf("Enter Name: ");
   scanf("%s", name);

   printf("Enter Email: ");
   scanf("%s", email);

   char query[100];

   sprintf(query, "INSERT INTO users (name, email) VALUES ('%s', '%s')", name, email);

   if (mysql_query(conn, query))
   {
      printf("Error executing query: %s\n", mysql_error(conn));
      exit(1);
   }

   printf("Data added successfully!\n");
}

void update_data()
{
   char id[10];
   char name[50];
   char email[50];

   printf("Enter the ID to update data: ");
   scanf("%s", id);

   printf("Enter Updated Name: ");
   scanf("%s", name);

   printf("Enter Updated Email: ");
   scanf("%s", email);

   char query[100];

   sprintf(query, "UPDATE users SET name='%s', email='%s' WHERE id='%s'", name, email, id);

   if (mysql_query(conn, query))
   {
      printf("Error executing query: %s\n", mysql_error(conn));
      exit(1);
   }

   printf("Data updated successfully!\n");
}

void delete_data()
{
   char id[10];

   printf("Enter the ID to delete data: ");
   scanf("%s", id);

   char query[100];

   sprintf(query, "DELETE FROM users WHERE id='%s'", id);

   if (mysql_query(conn, query))
   {
      printf("Error executing query: %s\n", mysql_error(conn));
      exit(1);
   }

   printf("Data deleted successfully!\n");
}

int main()
{
   connect_to_database();

   int choice;

   do
   {
      display_menu();

      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         query_all_data();
         break;

      case 2:
         query_data_by_id();
         break;

      case 3:
         add_data();
         break;

      case 4:
         update_data();
         break;

      case 5:
         delete_data();
         break;

      case 6:
         printf("Exiting program...\n");
         exit(0);
         break;

      default:
         printf("Invalid choice. Please try again.\n");
         break;
      }
   } while (choice != 6);

   mysql_close(conn); // Close MySQL connection

   return 0;
}

void display_menu()
{
   printf("\n----------MENU----------\n");
   printf("1. Display All Data\n");
   printf("2. Display Data by ID\n");
   printf("3. Add Data\n");
   printf("4. Update Data\n");
   printf("5. Delete Data\n");
   printf("6. Exit\n");
}